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

/*
all functions of this file: 
return 1 -> the input is invalid
return 0 -> the input is valid
*/

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

/*
compare two strings
return the difference between the two elements that diverge
if there is no difference (the strings are identical) it return 0
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
return 1 -> there is things that are not an int / the input is invalid
return 0 -> everything is an int / the input is valid
*/
int	int_only(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') ||
			(argv[i][j] == '+' || argv[i][j] == '-'))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

/*
return 1 -> there is a duplicate in the input / the input is invalid
return 0 -> there is no duplicate / the input is valid
*/
int	check_for_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
return 1 -> the input is invalid
return 0 -> the input is valid
*/
int	check_correct_value(int argc, char **argv)
{
	int	i;
	int	element;

	i = 1;
	if (check_for_duplicate(argc, argv) == 1)
		return (1);
	if (int_only(argv) == 1)
		return (1);
	while (*argv[i])
	{
		element = ft_atoi(argv[i]);
		if (element < INT_MAX && element > INT_MIN)
			i++;
		else
			return (1);
		return (0);
	}
	return (0);
}
