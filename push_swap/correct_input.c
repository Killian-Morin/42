/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:51:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 13:51:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	ft_atoi(const char	*str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * signe);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*should return 1 if there is a duplicate, 0 if not duplicate*/
int	check_for_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
/*should return 1 if the input has an error, 0 if the input is correct*/
int	check_correct_value(char **argv)
{
	int	i;
	int	element;

	i = 1;
	while (*argv[i])
	{
		element = ft_atoi(argv[i]);
		if (INT_MAX > element && INT_MIN < element)
			return (0);
		else
			return (1);
		i++;
	}
	if (check_for_duplicate(argv) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		printf("%d\n", check_correct_value(argv));
		printf("%d\n", check_for_duplicate(argv));
	}
	return (0);
}