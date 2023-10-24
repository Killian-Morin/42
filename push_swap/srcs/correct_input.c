/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:51:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
return 1 -> the input is invalid (some are not an int)
return 0 -> the input is valid (all int)
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
return 1 -> the input is invalid (duplicate present)
return 0 -> the input is valid (only unique elements)
*/
int	check_for_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
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

/*
return 1 -> the input is invalid
return 0 -> the input is valid
la var element est en long int pour prendre le retour de ft_atoi
afin de gerer correctement les int min & max
*/
int	check_correct_value(int argc, char **argv)
{
	int			i;
	long int	element;
	char		**av;

	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		av = argv;
	}
	if (!av)
		return (1);
	if (check_for_duplicate(av) == 1)
		return (1);
	if (int_only(av) == 1)
		return (1);
	while (av[i])
	{
		element = ft_ascii_to_long_int(av[i]);
		if (element > INT_MAX || element < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}
