/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:43:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/15 11:13:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	init id with the number of the philo,
	init meal_ate for the number of meal ate will serve to meal_to_eat reached,
	init time_last_meal with the current time,
	next will be init later,
	init table with table,
	create a mutex for the fork,
		if an error occur from the creation of a mutex, will writes the error
		and return until the main to free all and stop the program here.
*/
t_philo	*init_philo(t_table *t, int i)
{
	t_philo		*cur;

	cur = malloc(sizeof(t_philo));
	if (!cur)
		return (NULL);
	cur->id = i;
	cur->meal_ate = 0;
	cur->time_last_meal = get_time();
	cur->next = NULL;
	cur->table = t;
	if (pthread_mutex_init(&cur->fork, NULL) != 0)
	{
		printf("Error during the creation of a mutex\n");
		return (NULL);
	}
	return (cur);
}

/*
	init nbr_philo with the second av converted to int
	init philo_dead is a signal to indicate if a philo of the table died
	init die_time with the third av converted to int
	init eat_time with the fourth av converted to int
	init sleep_time with the fifth av converted to int
	if there is a sixth av then
		init meal_to_eat with it
	else init at -1
	philo_prime will be init later with the philo with the id = 1
*/
t_table	*init_table(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nbr_philo = ft_atoi(av[1]);
	table->philo_dead = 0;
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		table->meal_to_eat = ft_atoi(av[5]);
	else
		table->meal_to_eat = -1;
	table->philo_prime = NULL;
	return (table);
}
