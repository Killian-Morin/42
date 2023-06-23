/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:37 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/23 15:40:26 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	For each philo, create a thread that will execute the function passed, here
		cycle().
	Since pthread_join is in another loop, all thread are created and active
	at the same time.
	(If an error occur with the function, will writes the error, free all
	and return to stop the program here.)
*/
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

/*
	depending on the rank of the philo (even or not) sleep a bit or directly
	start the loop.
	in the loop, check if possible to do something: a philo is not already 
	dead, all philo did not eat all necessary meals to end the simulation.
	if all those conditions are filled then eat, sleep and think,
	else if even one of those conditions is not filled then break.
*/
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
