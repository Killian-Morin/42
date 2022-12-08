/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:55:54 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/03 12:57:21 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	*ret;

	i = 0;
	signe = 0;
	ret = 0;
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe++;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		ret[i] = str[i];
		i++;
	}
	return (*ret);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_atoi(argv[1]));
	}
	return (0);
}
