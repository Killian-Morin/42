/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	t_table	*t;

	if (check_args(ac, av))
		return (1);
	t = init_table(ac, av);
	if (!t)
		return (1);
	if (init_all_philo(t))
	{
		ft_free_all(t);
		return (1);
	}
	if (start_simulation(t))
		return (1);
	ft_free_all(t);
	return (0);
}
