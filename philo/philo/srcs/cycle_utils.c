/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:42:24 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	if can lock the var checked (nbr_death),
	if there has been no death and all philo didn't ate enough
		unlock the var checked and return 1 (do the action)
	else
		unlock the var checked and return 0 (don't do the action)
*/
int	can_make_action(t_philo *philo)
{
	if (!pthread_mutex_lock(&philo->table->m_nbr_death))
	{
		if (philo->table->nbr_death == 0
			&& meal_to_eat_reached(philo->table))
		{
			pthread_mutex_unlock(&philo->table->m_nbr_death);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->m_nbr_death);
	}
	return (0);
}

/*
	for all philo, if can lock the var checked (meal_ate),
	if a philo didn't eat enough or if meal_to_eat isn't defined
		unlock the var checked and return 1
	else
		unlock the var checked and pass to the next philo
	if all philo ate enough then return 0.
*/
int	meal_to_eat_reached(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (philo)
	{
		if (!pthread_mutex_lock(&philo->m_meal_ate))
		{
			if (t->meal_to_eat == -1 || philo->meal_ate < t->meal_to_eat)
			{
				pthread_mutex_unlock(&philo->m_meal_ate);
				return (1);
			}
			pthread_mutex_unlock(&philo->m_meal_ate);
		}
		philo = philo->next;
	}
	return (0);
}

/*
	if can lock the var checked (time_last_meal),
	if the time passed since the last meal is greater than time_to_die
		unlock the var checked and return 1,
	else
		unlock the var checked and return 0
*/
int	time_to_die_reached(t_philo *philo)
{
	if (!pthread_mutex_lock(&philo->m_time_last_meal))
	{
		if (get_time_pass(philo->time_last_meal, get_time())
			>= philo->table->die_time)
		{
			pthread_mutex_unlock(&philo->m_time_last_meal);
			return (1);
		}
		pthread_mutex_unlock(&philo->m_time_last_meal);
	}
	return (0);
}
