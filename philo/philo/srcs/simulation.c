/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:18:52 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 16:12:36 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	simulation_for_one(t_philo *philo)
{
	printf("%ld\t|%d|\thas taken a fork\n",
		get_time_pass(philo->table->start_time, get_time()), philo->id);
	custom_sleep(philo->table->die_time);
	printf("%ld\t|%d|\tdied\n",
		get_time_pass(philo->table->start_time, get_time()), philo->id);
}

void	start_simulation(t_table *t)
{
	if (t->nbr_philo == 1)
		simulation_for_one(t->first_philo);
	else
	{
		start_thread(t);
		checker_for_philos(t);
	}
}

/*
	for the moment works witout this in the while(1) of checker_for_philos
	is a bit of a equivalent
*/
void	infinite_loop(t_table *t, t_philo **philo)
{
	if (!(*philo))
		*philo = t->first_philo;
}

void	join_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}

void	checker_for_philos(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (1)
	{
		if (time_to_die_reached(philo))
		{
			philo_die(philo);
			break ;
		}
		else if (!check_meal_to_eat_reached(t))
		{
			if (t->meal_to_eat != -1)
				printf("Awesome ! All |%d| philosophers ate |%d| meals\n",
					t->nbr_philo, t->meal_to_eat);
			break ;
		}
		philo = philo->next;
		if (!philo)
			philo = t->first_philo;
	}
	join_thread(t);
}
