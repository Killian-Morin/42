/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:04:17 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/26 13:55:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	change_fork(t_philo *philo)
{
	philo->state = TAKE_FORK;
	printf("%ld %d has taken a fork\n", get_time_pass(philo->time->start_time,
			get_time()), philo->id);
}

void	change_eat(t_philo *philo)
{
	philo->state = EAT;
	printf("%ld %d is eating\n", get_time_pass(philo->time->start_time,
			get_time()), philo->id);
}

void	change_sleep(t_philo *philo)
{
	philo->state = SLEEP;
	printf("%ld %d is sleeping\n", get_time_pass(philo->time->start_time,
			get_time()), philo->id);
}

void	change_think(t_philo *philo)
{
	philo->state = THINK;
	printf("%ld %d is thinking\n", get_time_pass(philo->time->start_time,
			get_time()), philo->id);
}

void	change_die(t_philo *philo)
{
	philo->state = DEAD;
	printf("%ld %d died\n", get_time_pass(philo->time->start_time,
			get_time()), philo->id);
}
