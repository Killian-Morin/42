/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:04:02 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/31 17:07:03 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_assignation_simple(char *argv[])
{
	unsigned int	valeur;

	valeur = atoi(argv[1]);
	valeur = malloc(10 * sizeof(argv[1]);
}
/*variable a free quand meme*/

void	ft_assignation_double(char *argv[], char *dictionnaire)
{
	unsigned int	valeur;

	dictionnaire = argv[1];
	dictionnaire = malloc(10 * sizeof(argv[1]);
	valeur = atoi(argv[2]);
	valeur = malloc(10 * sizeof(argv[2]);
}
/*ces variables doivent etre liberees mais dans main non?*/

void	ft_compteur(unsigned int v)
{
	int	i;

	i = 0;
	while (v)
	{
		i++;
	}
	if (i == 1)
	{
		ft_putchar(v);
	}
	else if (i >= 2)
	{
		ft_putchar(v);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2 && argv[1][i] >= 0 && argv[1][i] <= 2147483647)
	{
		ft_assignation_simple(argv[1][i]);
		i++;
	}
	else if (argc == 3 && argv[1] && argv[2][i] > 0 && argv[2][i])
	{
		ft_assignation_double(argv[2][i], argv[1]);
		i++;
	}
	else
		write(1, "Error\n", 6);
}
