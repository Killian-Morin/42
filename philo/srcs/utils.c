/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:19:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/26 12:46:52 by kmorin           ###   ########.fr       */
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
