/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:46:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/14 17:32:59 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	return the time passed between the two arg
	start is usually the start_time / the time at which I begin to create
	the philos
*/
long int	get_time_pass(long int start, long int end)
{
	return (end - start);
}

/*
	get the value, then converts it to milliseconds:
		with *1000 for the seconds and
		with /1000 for the microseconds
	add both and return the converted time to milliseconds.
*/
long int	get_time(void)
{
	struct timeval	tmp;
	long int		time;
	long int		second;
	long int		microsecond;

	gettimeofday(&tmp, NULL);
	second = tmp.tv_sec * 1000;
	microsecond = tmp.tv_usec / 1000;
	time = second + microsecond;
	return (time);
}

/*
	time_to_wait is the total time to wait, precised by either time_to_die,
	time_to_eat or time_to_sleep in milliseconds.
	time_now get the current time.
	timer get the time pass between now and the init of start_time (usually 0).
	the while is for doing the usleep the right amount of time,
	it exit when timer reach time_to_wait, meaning we usleep the right
	amount of milliseconds.
	Serves to usleep the right amount of milliseconds.
*/
void	custom_sleep(long int time_to_wait)
{
	long int	time_now;
	long int	timer;

	time_now = get_time();
	timer = get_time_pass(time_now, get_time());
	while (timer < time_to_wait)
	{
		timer = get_time_pass(time_now, get_time());
		usleep(time_to_wait / 10);
	}
}
