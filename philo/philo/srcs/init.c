/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:12 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 15:52:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	pthread_mutex_init(&cur->m_meal_ate, NULL);
	pthread_mutex_init(&cur->m_time_last_meal, NULL);
	pthread_mutex_init(&cur->m_fork, NULL);
	cur->next = NULL;
	cur->table = t;
	return (cur);
}

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
	pthread_mutex_init(&t->m_nbr_death, NULL);
	return (t);
}
