/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:16:50 by killian           #+#    #+#             */
/*   Updated: 2023/06/14 13:55:35 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (fork != NULL && pthread_mutex_lock(fork) == 0)
	{
		if (check_can_make_action(philo))
		{
			printf("%ld\t%d has taken a fork\n",
				get_time_pass(philo->time->start_time, get_time()), philo->id);
			return (1);
		}
	}
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (philo_take_fork(philo, &philo->fork)
		&& philo_take_fork(philo, philo->next_fork))
	{
		if (check_can_make_action(philo))
		{
			printf("%ld\t%d is eating\n", get_time_pass(philo->time->start_time,
					get_time()), philo->id);
			philo->meal_ate += 1;
			philo->time_last_meal = get_time();
			custom_sleep(philo->time->eat_time);
		}	
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	philo_think(t_philo *philo)
{
	if (check_can_make_action(philo))
	{
		printf("%ld\t%d is thinking\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (check_can_make_action(philo))
	{
		printf("%ld\t%d is sleeping\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
		custom_sleep(philo->time->sleep_time);
	}
}

void	philo_die(t_philo *philo)
{
	if (check_can_make_action(philo))
	{
		philo->table->philo_dead += 1;
		printf("%ld\t%d died\n", get_time_pass(philo->time->start_time,
				get_time()), philo->id);
	}
}
