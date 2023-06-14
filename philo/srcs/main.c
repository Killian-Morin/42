/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:33:17 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/14 17:57:00 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	For each philo/thread, join/wait for it to finish.
	If an error occur with the function, will writes the error, free all
	and return to the main that will return with an error.
*/
int	join_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->philo_prime;
	while (philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Error while waiting for a thread\n");
			ft_free_all(t);
			return (1);
		}
		philo = philo->next;
	}
	return (0);
}

/*
	check only if they are valid arguments, it does not initialize anything
*/
int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
			printf("Sorry, not enough arguments\n");
		else if (ac > 6)
			printf("Sorry, too many arguments\n");
		return (1);
	}
	else if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0
		|| ft_atoi(av[4]) <= 0 || (ac == 6 && ft_atoi(av[5]) <= 0))
	{
		printf("Sorry, not a valid argument\n");
		return (1);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (check_args(ac, av))
		return (-1);
	table = init_table(av);
	table->time = init_time(ac, av);
	if (setup_each_philo(table))
	{
		ft_free_all(table);
		return (-1);
	}
	if (table->nbr_philo == 1)
	{
		cycle_for_one_philo(table->philo_prime);
		return (0);
	}
	else if (setup_thread(table))
		return (-1);
	checker_end_of_routine(table);
	if (join_thread(table))
		return (-1);
	ft_free_all(table);
	return (0);
}
