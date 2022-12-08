/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impression_cas_sur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:17:51 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/24 13:25:38 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_quatre_y(char	*argv[])
{
	int	x;
	int	y;
	int	i;
	int	input;

	input[i] = argv[i];
	if (input[i] == 4)
	{
		x = 1;
		y = 1;
		i = 1;
		while (y <= 4)
		{
			write(1, i, 1);
			i++;
			write(1, "\n", 1);
		}
	}
}

void	ft_quatre_x(char	*argv[])
{
	int	x;
	int	y;
	int	i;
	int	input;

	if (input[i] == 4)
	{
		x = 1;
		y = 1;
		i = 1;
		while (x <= 4)
		{
			write(1, i, 1);
			i++;
			write(1, "\n", 1);
		}
	}
}

void	ft_un(char	*argv[])
{
	int	x;
	int	y;
	int	i;
	int	input;

	if (input[i] == 1)
	{
		x = i + 1;
		write(1, 4, 1);
	}
	else if (input[i] == 1)
	{
		y = i + 1;
		write(1, 4, 1);
	}
	else if (input[i] == 1)
	{
		x = i - 1;
		write(1, 4, 1);
	}
	else if (input[i] == 1)
	{
		y = i - 1;
		write(1, 4, 1);
	}
}
