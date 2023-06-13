/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:09:12 by killian           #+#    #+#             */
/*   Updated: 2023/06/13 14:11:27 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	check for the philo passed in parameter if the time of
	his last meal is greater, thus older than the time to die then return 1
	else return 0
*/
int	check_time_to_die_reached(t_philo *philo)
{
	if (get_time_pass(philo->time_last_meal, get_time())
		>= philo->time->die_time)
		return (1);
	else
		return (0);
}

/*
	The return value will be utilized to check if we can do an action:
	return 1 will indicate that we need to do the action since the nb of meals
	was not specified (-1) or that the number of meals is not reached for him,
	return 0 will indicate that we don't need to do the action
*/
int	check_meals_reached(t_philo *philo)
{
	if (philo->time->meal_to_eat == -1
		|| philo->meal_ate < philo->time->meal_to_eat)
		return (1);
	return (0);
}
