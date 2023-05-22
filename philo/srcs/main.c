/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:33:17 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/22 15:43:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Sorry not the right amount of arguments\n");
		return (1);
	}
	else if (ft_atoi(av[1]) < 1)
	{
		printf("Sorry not a valid amount of philosopher\n");
		return (1);
	}
	else
		return (0);
}

long int	get_time(void)
{
	struct timeval	tmp;
	long int		time;
	long int		second;
	long int		microsecond;

	gettimeofday(&tmp, NULL);
	second = tmp.tv_sec * 1000;
	microsecond = tmp.tv_usec / 1000;
	time = second + microsecond;
	return (time);
}

void	init_data(int ac, char **av, t_philo *p)
{
	p->table->nbr_philo = ft_atoi(av[1]);
	p->time->die_time = ft_atoi(av[2]);
	p->time->eat_time = ft_atoi(av[3]);
	p->time->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		p->time->meal_to_eat = ft_atoi(av[5]);
	printf("%d\n", p->table->nbr_philo);
	printf("%d\n", p->time->die_time);
	printf("%d\n", p->time->eat_time);
	printf("%d\n", p->time->sleep_time);
	p->time->start_time = get_time();
}

int	main(int ac, char **av)
{
	t_philo	*p;

	if (check_args(ac, av) == 1)
		return (1);
	p = malloc(sizeof(p));
	if (!p)
		return (1);
	init_data(ac, av, p);
}
