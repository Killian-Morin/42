/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:48:45 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/17 14:58:13 by rmorand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int		which_angle(int current_line, int current_col, int x, int y);
int		is_border_line(int current_line, int x);
int		is_border_col(int current_col, int y);
void	print_char(int current_line, int current_col, int x, int y);
int		ft_putchar(char c);

static const int	g_true = 1;
static const int	g_false = 0;
static const int	g_angle_top_left = 1;
static const char	g_angle_top_left_char = '/';
static const int	g_angle_top_right = 2;
static const char	g_angle_top_right_char = '\\';
static const int	g_angle_bottom_left = 3;
static const char	g_angle_bottom_left_char = '\\';
static const int	g_angle_bottom_right = 4;
static const char	g_angle_bottom_right_char = '/';
static const char	g_border_line_char = '*';
static const char	g_border_col_char = '*';
static const char	g_empty_char = ' ';

void	rush(int x, int y)
{
	int	current_col;
	int	current_line;

	if (x < 0)
	{
		write(2, "Negative value of x detected, use of absolute value.\n", 53);
		x = x * -1;
	}
	if (y < 0)
	{
		write(2, "Negative value of y detected, use of absolute value.\n", 53);
		y = y * -1;
	}
	current_line = 1;
	while (current_line <= y)
	{
		current_col = 1;
		while (current_col <= x)
		{
			print_char(current_line, current_col, x, y);
			current_col++;
		}
		ft_putchar('\n');
		current_line++;
	}
}

int	which_angle(int current_line, int current_col, int x, int y)
{
	if (current_col == 1 && current_line == 1)
		return (g_angle_top_left);
	else if (current_col == y && current_line == 1)
		return (g_angle_top_right);
	else if (current_col == 1 && current_line == x)
		return (g_angle_bottom_left);
	else if (current_col == y && current_line == x)
		return (g_angle_bottom_right);
	else
		return (g_false);
}

int	is_border_line(int current_line, int x)
{
	if (current_line == 1 || current_line == x)
		return (g_true);
	return (g_false);
}

int	is_border_col(int current_col, int y)
{
	if (current_col == 1 || current_col == y)
		return (g_true);
	return (g_false);
}

void	print_char(int current_col, int current_line, int x, int y)
{			
	int	angle;

	angle = which_angle(current_line, current_col, x, y);
	if (angle)
	{
		if (angle == g_angle_top_left)
			ft_putchar(g_angle_top_left_char);
		if (angle == g_angle_top_right)
			ft_putchar(g_angle_top_right_char);
		if (angle == g_angle_bottom_left)
			ft_putchar(g_angle_bottom_left_char);
		if (angle == g_angle_bottom_right)
			ft_putchar(g_angle_bottom_right_char);
	}
	else if (is_border_line(current_line, x))
		ft_putchar(g_border_line_char);
	else if (is_border_col(current_col, y))
		ft_putchar(g_border_col_char);
	else
		ft_putchar(g_empty_char);
}
