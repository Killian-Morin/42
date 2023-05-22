/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:19:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/22 13:24:18 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int	res;
	int	signe;

	res = 0;
	signe = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * signe);
}
