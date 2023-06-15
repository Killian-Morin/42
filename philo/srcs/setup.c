/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:06:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/15 11:04:42 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	For each philo, create a thread that will execute the function passed, here
		routine.
	Since pthread_join is in another loop, all thread are created and active
	at the same time.
	If an error occur with the function, will writes the error, free all
	and return to stop the program here.
*/
int	setup_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->philo_prime;
	while (philo)
	{
		if (pthread_create(&philo->thread, NULL, &routine, philo) != 0)
		{
			printf("Error during the creation of a thread\n");
			ft_free_all(t);
			return (1);
		}
		philo = philo->next;
	}
	return (0);
}

/*
	iterate through all philo to init their next_fork
	with the address of their next philo fork's.
	if nbr_philo > 1 the next_fork of the last philo needs to points to the fork
		of the first philo (thus the if and the init)
	else only one philosopher, so no other fork so points to NULL.
*/
void	setup_fork_next(t_table *t)
{
	t_philo	*philo;
	t_philo	*tmp;

	philo = t->philo_prime;
	while (philo->next)
	{
		philo->next_fork = &philo->next->fork;
		philo = philo->next;
	}
	if (t->nbr_philo > 1)
	{
		tmp = t->philo_prime;
		philo->next_fork = &tmp->fork;
	}
	else
		philo->next_fork = NULL;
}

/*
	init the next of the philo passed in arg
	if philo_prime is not init we are the first call/philo and init it
	iterate to the last philo that has his next init to the philo sent in arg.
*/
void	setup_philo_around_table(t_table *t, t_philo *philo)
{
	t_philo	*tmp;

	if (!t->philo_prime)
		t->philo_prime = philo;
	else
	{
		tmp = t->philo_prime;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = philo;
	}
}

/*
	init now, at the creation of the philos, start_time in milliseconds.
	
	the while will call for each philo:
		init_philo() to init some var of his struct,
		setup_philo_around_table() will init his next.
	setup_fork_next() will init the next_fork for each philo.
*/
int	setup_each_philo(t_table *t)
{
	int		i;
	t_philo	*philo;

	i = 1;
	t->start_time = get_time();
	while (i <= t->nbr_philo)
	{
		philo = init_philo(t, i);
		if (!philo)
			return (1);
		setup_philo_around_table(t, philo);
		i++;
	}
	setup_fork_next(t);
	return (0);
}
