/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:17:25 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 16:09:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (!pthread_mutex_lock(fork))
	{
		if (can_make_action(philo))
		{
			printf("%ld\t|%d|\thas taken a fork\n",
				get_time_pass(philo->table->start_time, get_time()), philo->id);
			return (1);
		}
	}
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (philo_take_fork(philo, &philo->m_fork)
		&& philo_take_fork(philo, philo->m_next_fork))
	{
		if (can_make_action(philo))
		{
			if (!pthread_mutex_lock(&philo->m_meal_ate)
				&& !pthread_mutex_lock(&philo->m_time_last_meal))
			{
				printf("%ld\t|%d|\tis eating\n", get_time_pass
					(philo->table->start_time, get_time()), philo->id);
				philo->meal_ate += 1;
				philo->time_last_meal = get_time();
				pthread_mutex_unlock(&philo->m_meal_ate);
				pthread_mutex_unlock(&philo->m_time_last_meal);
				custom_sleep(philo->table->eat_time);
			}
		}
		pthread_mutex_unlock(&philo->m_fork);
		pthread_mutex_unlock(philo->m_next_fork);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (can_make_action(philo))
	{
		printf("%ld\t|%d|\tis sleeping\n",
			get_time_pass(philo->table->start_time, get_time()), philo->id);
		custom_sleep(philo->table->sleep_time);
	}
}

void	philo_think(t_philo *philo)
{
	if (can_make_action(philo))
	{
		printf("%ld\t|%d|\tis thinking\n",
			get_time_pass(philo->table->start_time, get_time()), philo->id);
	}
}

void	philo_die(t_philo *philo)
{
	if (can_make_action(philo))
	{
		if (!pthread_mutex_lock(&philo->table->m_nbr_death))
		{
			philo->table->nbr_death += 1;
			printf("%ld\t|%d|\tdied\n",
				get_time_pass(philo->table->start_time, get_time()), philo->id);
			pthread_mutex_unlock(&philo->table->m_nbr_death);
		}
	}
}
