/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:37 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:38 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	For each philo, create a thread that will execute the function passed, here
		cycle().
	Since pthread_join is in another loop, all thread are created and active
	at the same time.
	If an error occur with the function, will writes the error, return to
	start_simulation() to free all and return to the main.
*/
int	start_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (philo)
	{
		if (pthread_create(&philo->thread, NULL, &cycle, philo) != 0)
		{
			printf("Error during the creation of a thread\n");
			return (1);
		}
		philo = philo->next;
	}
	return (0);
}

/*
	depending on the rank of the philo (even or not) sleep a bit or directly
	start the loop.
	in the loop, check if possible to do something: a philo is not already 
	dead & all philo did not eat all necessary meals to end the simulation.
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
