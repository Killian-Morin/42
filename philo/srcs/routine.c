/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:42 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/26 15:23:22 by kmorin           ###   ########.fr       */
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
	change_fork(philo);
	custom_sleep(philo->time->die_time);
	change_die(philo);
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
	while (1)
	{
		break ;
	}
	return (NULL);
}
