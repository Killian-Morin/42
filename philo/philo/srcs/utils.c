/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:10 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:45 by kmorin           ###   ########.fr       */
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
	a malloc for table, time and one for each philo so need for each philo to:
	destroy the mutex of his variables that needed to be protected,
		detach his thread
	and free his struct.
	once all philos are cleared:
	destroy the mutex of the struct table and free it.
*/
void	ft_free_all(t_table *t)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	while (i <= t->nbr_philo)
	{
		tmp = t->first_philo;
		t->first_philo = t->first_philo->next;
		pthread_mutex_destroy(&tmp->m_fork);
		pthread_mutex_destroy(&tmp->m_meal_ate);
		pthread_mutex_destroy(&tmp->m_time_last_meal);
		pthread_detach(tmp->thread);
		free(tmp);
		i++;
	}
	pthread_mutex_destroy(&t->m_nbr_death);
	free(t);
}
