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

#include "../includes/push_swap.h"

/*
all functions of this file: 
return 1 -> the input is invalid
return 0 -> the input is valid
*/

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
