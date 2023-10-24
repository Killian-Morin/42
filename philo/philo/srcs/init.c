/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:12 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	init id with the number of the philo,
	init meal_ate for the number of meal ate will serve to meal_to_eat reached,
	init time_last_meal with the current time,
	thread will be init later,
	init the mutex for the vars,
		that needs protections/access via different threads.
	next will be init later,
	init table with table,
	if an error occur from the creation of a mutex, will writes the error
	and return until the main to free all and stop the program here.
*/
t_philo	*init_philo(t_table *t, int i)
{
	t_philo	*cur;

	cur = (t_philo *)malloc(sizeof(t_philo));
	if (!cur)
		return (NULL);
	cur->id = i;
	cur->meal_ate = 0;
	cur->time_last_meal = get_time();
	cur->thread = NULL;
	if (pthread_mutex_init(&cur->m_meal_ate, NULL) != 0
		|| pthread_mutex_init(&cur->m_time_last_meal, NULL) != 0
		|| pthread_mutex_init(&cur->m_fork, NULL) != 0)
	{
		printf("Error during the creation of a mutex\n");
		return (NULL);
	}
	cur->next = NULL;
	cur->table = t;
	return (cur);
}

/*
	init the next of the philo passed in arg
	if first_philo is not init it's the first call/philo, thus init first_philo
	iterate to the last philo that has his next init to the philo sent in arg.
*/
void	init_next_philo(t_table *t, t_philo *philo)
{
	t_philo	*tmp;

	if (!t->first_philo)
		t->first_philo = philo;
	else
	{
		tmp = t->first_philo;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = philo;
	}
}

/*
	iterate through all philo to init their next_fork
	with the address of their next philo fork's.
	if only one philo, no other fork so his next_fork points to NULL.
	else the next_fork of the last philo needs to points to the fork
		of the first philo
*/
void	init_next_fork(t_table *t)
{
	t_philo	*tmp;

	tmp = t->first_philo;
	while (tmp->next)
	{
		tmp->m_next_fork = &tmp->next->m_fork;
		tmp = tmp->next;
	}
	if (t->nbr_philo == 1)
		tmp->m_next_fork = NULL;
	else
		tmp->m_next_fork = &t->first_philo->m_fork;
}

/*
	init now, at the creation of the philos, start_time in milliseconds.
	
	the while will call for each philo:
		init_philo() to init all var of his struct,
		init_next_philo() will init his var next (to indicate the next philo).
	init_fork_next() will init the next_fork for each philo.
*/
int	init_all_philo(t_table *t)
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
		init_next_philo(t, philo);
		i++;
	}
	init_next_fork(t);
	return (0);
}

/*
	init nbr_philo with the second av converted to int
	init die_time with the third av converted to int
	init eat_time with the fourth av converted to int
	init sleep_time with the fifth av converted to int
	if there is a sixth av then init meal_to_eat with it
	else init at -1
	init philo_dead is a signal to indicate if a philo of the table died
	philo_prime will be init later with the philo with the id = 1
	init the mutex that will protect the signal to indicate a death.
	if an error occur from the creation of a mutex, will writes the error
	and return until the main to stop the program here.
*/
t_table	*init_table(int ac, char **av)
{
	t_table	*t;

	t = (t_table *)malloc(sizeof(t_table));
	if (!t)
		return (NULL);
	t->nbr_philo = ft_atoi(av[1]);
	t->die_time = ft_atoi(av[2]);
	t->eat_time = ft_atoi(av[3]);
	t->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		t->meal_to_eat = ft_atoi(av[5]);
	else
		t->meal_to_eat = -1;
	t->nbr_death = 0;
	t->first_philo = NULL;
	if (pthread_mutex_init(&t->m_nbr_death, NULL) != 0)
	{
		printf("Error during the creation of a mutex\n");
		return (NULL);
	}
	return (t);
}
