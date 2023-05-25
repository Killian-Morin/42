/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:19:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/25 15:54:48 by kmorin           ###   ########.fr       */
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
	get the value, then converts it to milliseconds:
		with *1000 for the seconds and
		with /1000 for the microseconds
	add both and return the converted time to milliseconds.
*/
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
