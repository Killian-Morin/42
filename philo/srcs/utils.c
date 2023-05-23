/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:19:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/23 15:29:04 by kmorin           ###   ########.fr       */
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
