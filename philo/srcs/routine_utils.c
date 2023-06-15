/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:09:12 by killian           #+#    #+#             */
/*   Updated: 2023/06/15 10:11:04 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	return 1 if the time passed since the last meal is greater than time_to_die
	return 0 otherwise
*/
int	check_time_to_die_reached(t_philo *philo)
{
	if (get_time_pass(philo->time_last_meal, get_time())
		>= philo->time->die_time)
		return (1);
	return (0);
}

/*
	return 1 if there are a number of meals to reach,
	and that the current philo didn't reach it.

	return 0 if there are no number of meals to reach,
	or the philo already ate enough.
*/
int	check_meals_reached(t_philo *philo)
{
	if (philo->time->meal_to_eat == -1
		|| philo->meal_ate < philo->time->meal_to_eat)
		return (1);
	return (0);
}

/*
	check if all philo ate enough to reach meal_to_eat.
	if a philo didn't eat enough then return 0 and will probably do the action

	if all philo ate enough then return 1 and will not do the action
*/
int	all_philo_ate_enough(t_table *table)
{
	t_philo	*philo;

	philo = table->philo_prime;
	while (philo)
	{
		if (check_meals_reached(philo))
			return (0);
		philo = philo->next;
	}
	return (1);
}

/*
	a philo can make an action (return 1) if no philo is already dead (== 0)
	and if all philos didn't ate enough.
	if one of those two conditions is false,
	then return 0 and will not do the action.
*/
int	check_can_make_action(t_philo *philo)
{
	if (philo->table->philo_dead == 0 && !all_philo_ate_enough(philo->table))
		return (1);
	return (0);
}
