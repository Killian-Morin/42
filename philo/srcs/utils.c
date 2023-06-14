/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:19:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/14 18:02:03 by killian          ###   ########.fr       */
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
	a malloc for table, time and one for each philo so theorically
	for each philo: will destroy the mutex of his fork, detach his thread
	and free his struct.
	free a single time the struct time and the struct table.
*/
void	ft_free_all(t_table *table)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	while (i <= table->nbr_philo)
	{
		tmp = table->philo_prime;
		table->philo_prime = table->philo_prime->next;
		pthread_mutex_destroy(&tmp->fork);
		pthread_detach(tmp->thread);
		free(tmp);
		i++;
	}
	free(table->time);
	free(table);
}
