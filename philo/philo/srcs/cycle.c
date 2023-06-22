/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:37 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 15:07:17 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (philo)
	{
		pthread_create(&philo->thread, NULL, &cycle, philo);
		philo = philo->next;
	}
}

void	*cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		custom_sleep(philo->table->eat_time / 2);
	while (1)
	{
		if (can_make_action(philo))
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		else
			break ;
	}
	return (NULL);
}
