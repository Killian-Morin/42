/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:33:17 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/25 16:19:38 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
			printf("Sorry, not enough arguments\n");
		else if (ac > 6)
			printf("Sorry, too many arguments\n");
		return (-1);
	}
	else if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0
		|| ft_atoi(av[4]) <= 0 || (ac == 6 && ft_atoi(av[5]) <= 0))
	{
		printf("Sorry, not a valid argument\n");
		return (-1);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (check_args(ac, av) == -1)
		return (-1);
	table = init_table(av);
	table->time = init_time(ac, av);
	if (philo_spawn(table) == -1)
	{
		ft_free(table);
		return (-1);
	}
	if (create_thread(table) == -1)
	{
		ft_free(table);
		return (-1);
	}
	if (pthread_join(table->philo_prime->thread, NULL) != 0)
		return (-1);
	ft_free(table);
	return (0);
}
