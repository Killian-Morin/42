/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:42 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/12 17:58:39 by killian          ###   ########.fr       */
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
	depending on the rank of the philo (pair or impair) start to eat now or
	wait a bit.
	in the loop, check if possible to do something: a philo is not already 
	dead, all philo did not eat all necessary meals to end the simulation or
	if the philo eat before the time_to_die.
	if all those conditions are filled the eat, sleep and think,
	else if even one of those conditions is not filled then break.

	change the position of the check_if_time_to_die from after
	start_eating to out of the while (1), that way it is suppose to philo_die.
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		custom_sleep(philo->time->eat_time / 2);
	while (1)
	{
		if (philo->table->philo_dead == 0 && check_meals_reached(philo) == 1
			&& check_time_to_die_reached(philo) == 0)
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		break ;
	}
	if (check_time_to_die_reached(philo) == 1 || philo->table->philo_dead == 1)
		philo_die(philo);
	return (NULL);
}
