/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:42 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/06 15:26:51 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*
	doing a simple usleep(time_to_wait * 1000) to convert to seconds
	is less precise than custom_sleep,
	there is always a little delay for the message died (02, 05 ...)
	but it is much smaller and easier
*/
void	cycle_for_one_philo(t_philo *philo)
{
	philo->state = TAKE_FORK;
	printf("%ld %d has taken a fork\n",
		get_time_pass(philo->time->start_time, get_time()), philo->id);
	custom_sleep(philo->time->die_time);
	philo_die(philo);
}

/*
	makes eating the philo with even id
	while the other one sleep during the meal
	they just wait for the others philo to finish their meal (no message print)
*/
void	start_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		philo_eat(philo);
	else
		custom_sleep(philo->time->eat_time);
}

/*
	depending on the rank of the philo (pair or impair) start to eat now or
	wait a bit -> need to do function.
	in the loop, check if possible to do something (a philo is not already 
	dead), if possible then eat, sleep and think else if not possible to do
	something then break;
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	start_eating(philo);
	if (check_if_time_to_die(philo) == 1)
	{
		philo_die(philo);
		return (NULL);
	}
	while (1)
	{
		if (philo->table->philo_dead == 0 && check_all_meals(philo->table) == 0
			&& philo->time_last_meal < philo->time->die_time)
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		break ;
	}
	return (NULL);
}
