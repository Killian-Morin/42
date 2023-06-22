/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:52:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 13:21:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_time_pass(long int start, long int end)
{
	return (end - start);
}

long int	get_time(void)
{
	struct timeval	tmp;
	long int		second;
	long int		microsecond;

	gettimeofday(&tmp, NULL);
	second = tmp.tv_sec * 1000;
	microsecond = tmp.tv_usec / 1000;
	return (second + microsecond);
}

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
