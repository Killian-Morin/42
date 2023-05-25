/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:06:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/25 13:59:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
    assign the next and prev of the philo passed in arg
    if just created the first philo/first iteration:
        assign philo_prime to this philo passed in arg
    WORKS JUST FINE
*/
void	philo_sit_at_table(t_table *t, t_philo *philo)
{
	t_philo	*tmp;

	if (t->philo_prime == NULL)
		t->philo_prime = philo;
	else
	{
		tmp = t->philo_prime;
		while (tmp->next)
			tmp = tmp->next;
		philo->prev = tmp;
		tmp->next = philo;
	}
}

/*
	init now start_time to get the current time in milliseconds,
		it get the time at the creation of the philos.
	
	the while will call for each philo,
		init_philo to init some var of the struct: the structs already init,
            the int/long int with common value for each philo or its id.
		philo_sit_at_table() will init next and prev of the philo just created

	after the while, still needs to init the var concerning the thread and mutex
    could do a function for each notion: the first one for the mutex var and
    the second one for the thread var
*/
void	philo_spawn(t_table *t)
{
	int		i;
	t_philo	*philo;

	i = 1;
	t->time->start_time = get_time();
	while (i <= t->nbr_philo)
	{
		philo = init_philo(t, i);
		philo_sit_at_table(t, philo);
		i++;
	}
}
