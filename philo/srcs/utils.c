/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:19:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/13 16:16:20 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * signe);
}

int	all_meals_reached(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = table->philo_prime;
	while (philo)
	{
		if (philo->meal_ate == philo->time->meal_to_eat
			&& philo->time->meal_to_eat != -1)
		{
			philo = philo->next;
			i++;
		}
		else
			break ;
	}
	if (i == table->nbr_philo && table->time->meal_to_eat != -1)
	{
		printf("Awesome ! All %d philosophers ate %d meals\n", table->nbr_philo,
			table->time->meal_to_eat);
		return (1);
	}
	return (0);
}

/*
	when using leaks -atExit -- have no leaks for the moment

	with 3 malloc for table, time and one for each philo

	add the function to destroy the mutex.
*/
void	ft_free(t_table *table)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	while (i <= table->nbr_philo)
	{
		tmp = table->philo_prime;
		table->philo_prime = table->philo_prime->next;
		pthread_mutex_destroy(&tmp->fork);
		free(tmp);
		i++;
	}
	free(table->time);
	free(table);
}
