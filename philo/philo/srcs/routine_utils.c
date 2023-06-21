/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:09:12 by killian           #+#    #+#             */
/*   Updated: 2023/06/21 15:07:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	return 1 if the time passed since the last meal is greater than time_to_die
	return 0 otherwise
*/
int	check_time_to_die_reached(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->mutex_time_last_meal) == 0)
	{
		if (get_time_pass(philo->time_last_meal, get_time())
			>= philo->table->die_time)
			return (1);
	}
	pthread_mutex_unlock(&philo->mutex_time_last_meal);
	return (0);
}

/*
	check if all philo ate enough to reach meal_to_eat (if defined).
	if a philo didn't eat enough or if meal_to_eat isn't defined
	then return 1 to indicate that it is safe to do another iteration.
	if all philo ate enough then return 0 to indicate that we can stop here.
*/
int	all_philo_ate_enough(t_table *t)
{
	t_philo	*philo;

	philo = t->philo_prime;
	while (philo)
	{
		if (pthread_mutex_lock(&philo->mutex_meal_ate) == 0
			&& (philo->table->meal_to_eat == -1
				|| philo->meal_ate < philo->table->meal_to_eat))
		{
			pthread_mutex_unlock(&philo->mutex_meal_ate);
			return (1);
		}
		philo = philo->next;
	}
	return (0);
}

/*
	a philo can make an action (return 1) if no philo is already dead (== 0)
	and if all philos didn't ate enough.
	if one of those two conditions is false,
	then return 0 and will not do the action.
*/
int	check_can_make_action(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->table->mutex_philo_dead) == 0)
	{
		if (philo->table->philo_dead == 0 && all_philo_ate_enough(philo->table))
		{
			pthread_mutex_unlock(&philo->table->mutex_philo_dead);
			return (1);
		}
	}
	return (0);
}

int	ate_enough_for_end(t_philo *philo)
{
	while (philo)
	{
		if (pthread_mutex_lock(&philo->mutex_meal_ate))
		{
			if (philo->meal_ate <= philo->table->meal_to_eat)
			{
				pthread_mutex_unlock(&philo->mutex_meal_ate);
				printf("la\n");
				return (0);
			}
			else
				philo = philo->next;
		}
		philo = philo->next;
	}
	return (1);
}
