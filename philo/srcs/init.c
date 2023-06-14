/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:43:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/14 18:03:17 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	for all malloc of structures:
		sizeof() with the size of the struct itself and
		not the variable which is a pointer to struct.
	
	might need a cast to the type of the variable (a pointer to struct),
	before the malloc (t_strut *)malloc...
	Thus far works just fine but in case of a problem try this solution.
*/

/*
	init id with the number of the philo,
	init meal_ate for the number of meal ate will serve to meal_to_eat reached,
	init time with the time from table->time,
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
	cur->time = t->time;
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
	init die_time with the third av converted to int
	init eat_time with the fourth av converted to int
	init sleep_time with the fifth av converted to int
	if there is a sixth av then
		init meal_to_eat with it
	else init at -1
*/
t_time	*init_time(int ac, char **av)
{
	t_time	*time;

	time = malloc(sizeof(t_time));
	if (!time)
		return (NULL);
	time->die_time = ft_atoi(av[2]);
	time->eat_time = ft_atoi(av[3]);
	time->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		time->meal_to_eat = ft_atoi(av[5]);
	else
		time->meal_to_eat = -1;
	return (time);
}

/*
	init nbr_philo with the second av converted to int
	init philo_dead is a signal to indicate if a philo of the table died
	time will be init later
	philo_prime will be init later with the philo with the id = 1
*/
t_table	*init_table(char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nbr_philo = ft_atoi(av[1]);
	table->philo_dead = 0;
	table->time = NULL;
	table->philo_prime = NULL;
	return (table);
}
