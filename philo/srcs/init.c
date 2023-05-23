/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:43:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/23 16:00:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    philo_sit_at_table(t_table *t, t_philo *philo)
{
    t_philo *tmp;

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

t_philo	*init_philo(t_table *t, int i)
{
	t_philo		*cur;

	cur = malloc(sizeof(cur));
	if (!cur)
		return (NULL);
	cur->num = i;
	cur->state = -1;
	cur->meal_ate = 0;
	cur->time_last_meal = t->time->start_time;
    cur->time = t->time;
    cur->next = NULL;
    cur->prev = NULL;
    cur->table = t;
	return (cur);
}

void    philo_spawn(t_table *t)
{
    int i;
    t_philo *philo;

    i = 1;
    while (i != t->nbr_philo)
    {
        philo = init_philo(t, i);
        philo_sit_at_table(t, philo);
        i++;
    }
}

t_time	*init_time(int ac, char **av)
{
	t_time	*time;

	time = malloc(sizeof(time));
	if (!time)
		return (NULL);
	time->die_time = ft_atoi(av[2]);
	time->eat_time = ft_atoi(av[3]);
	time->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		time->meal_to_eat = ft_atoi(av[5]);
	else
		time->meal_to_eat = -1;
	time->start_time = get_time();
	return (time);
}

t_table	*init_table(char **av)
{
	t_table	*table;

	table = malloc(sizeof(table));
	if (!table)
		return (NULL);
	table->nbr_philo = ft_atoi(av[1]);
	table->philo_dead = 0;
	table->time = NULL;
	table->philo_prime = NULL;
	return (table);
}
