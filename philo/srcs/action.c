/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:50 by killian           #+#    #+#             */
/*   Updated: 2023/06/06 17:01:20 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_take_fork(t_philo *philo)
{
	if (philo->table->philo_dead == 0 && philo->prev->state != EAT
		&& philo->next->state != EAT)
	{
		philo->state = TAKE_FORK;
		pthread_mutex_lock(&philo->fork);
		printf("%ld %d has taken a fork\n",
			get_time_pass(philo->time->start_time, get_time()), philo->id);
	}
}

void	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	if (philo->table->philo_dead == 0 && ((philo->next->state != TAKE_FORK
				&& philo->prev->state != TAKE_FORK)
			|| (philo->next->state != EAT
				&& philo->prev->state != EAT)))
	{
		pthread_mutex_lock(philo->next_fork);
		philo->state = EAT;
		printf("%ld %d is eating\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
		philo->meal_ate += 1;
		philo->time_last_meal = 0;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		custom_sleep(philo->time->eat_time);
	}
}

void	philo_think(t_philo *philo)
{
    if (philo->table->philo_dead == 0 && check_if_time_to_die(philo) == 0)
	{
		philo->state = THINK;
		printf("%ld %d is thinking\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (philo->table->philo_dead == 0 && check_if_time_to_die(philo) == 0)
	{
		philo->state = SLEEP;
		printf("%ld %d is sleeping\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
		custom_sleep(philo->time->sleep_time);
	}
}

void	philo_die(t_philo *philo)
{
	if (philo->table->philo_dead == 0 && check_if_time_to_die(philo) == 0)
	{
		philo->state = DEAD;
		philo->table->philo_dead = 1;
		printf("%ld %d died\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
	}
}
