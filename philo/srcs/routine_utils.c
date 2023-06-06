/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:09:12 by killian           #+#    #+#             */
/*   Updated: 2023/06/06 13:41:26 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	check for the philo passed in parameter if his last meal if older than
	the time to die then return 1 else return 0
*/
int	check_if_time_to_die(t_philo *philo)
{
	if (philo->time_last_meal >= philo->time->die_time)
		return (1);
	else
		return (0);
}

/*
	checks if all the philo have reached the number of meal_to_eat
*/
int	check_all_meals(t_table *table)
{
	t_philo	*tmp;

	tmp = table->philo_prime;
	while (tmp)
	{
		if (tmp->meal_ate == tmp->time->meal_to_eat)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}
