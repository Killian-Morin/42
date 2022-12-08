/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:34:28 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/24 13:26:32 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	coordinates_haut(char	*argv[])
{
	char	input[31];
	int		col1up;
	int		col2up;
	int		col3up;
	int		col4up;

	while (&input[0] != argv[7])
	{
		col1up = input[0];
		col2up = input[2];
		col3up = input[4];
		col4up = input[6];
		input[0]++;
	}
	return (0);
}

char	coordinates_bas(char	*argv[])
{
	char	input[31];
	int		col1down;
	int		col2down;
	int		col3down;
	int		col4down;

	while (&input[8] != argv[15])
	{
		col1down = input[8];
		col2down = input[10];
		col3down = input[12];
		col4down = input[14];
		input[8]++;
	}
	return (0);
}

char	coordinates_gauche(char	*argv[])
{
	char	input[31];
	int		row1left;
	int		row2left;
	int		row3left;
	int		row4left;

	while (&input[16] != argv[23])
	{
		row1left = input[16];
		row2left = input[18];
		row3left = input[20];
		row4left = input[22];
		input[16]++;
	}
	return (0);
}

char	coordinates_droit(char	*argv[])
{
	char	input[31];
	int		row1right;
	int		row2right;
	int		row3right;
	int		row4right;

	while (&input[24] == argv[30])
	{
		row1right = input[24];
		row2right = input[26];
		row3right = input[28];
		row4right = input[30];
		input[24]++;
	}
	return (0);
}
