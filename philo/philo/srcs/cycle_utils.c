/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:42:24 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 16:06:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	can_make_action(t_philo *philo)
{
	if (!pthread_mutex_lock(&philo->table->m_nbr_death))
	{
		if (philo->table->nbr_death == 0
			&& check_meal_to_eat_reached(philo->table))
		{
			pthread_mutex_unlock(&philo->table->m_nbr_death);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->m_nbr_death);
	}
	return (0);
}

int	check_meal_to_eat_reached(t_table *t)
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
