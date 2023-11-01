/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_walls2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:01:01 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/30 14:11:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error_map(int x, int y, t_file *f)
{
	free_tab_size(f->map, f->map_max_y);
	free_texture_file(f);
	printf(RED "Error\n");
	printf("Map error: Not closed at y = %d, x = %d\n" WHITE, y, x);
	exit (1);
}

void	check_angle(char **map, int x, int y, t_file *f)
{
	if (y > 0 && y < f->map_max_y && x > 0 && x < f->map_max_x)
	{
		if (map[y][x] != '-' && map[y][x] != '1')
			exit_error_map(x, y, f);
	}
}

int	helper(int x, int y, char **map, t_file *f)
{
	check_angle(map, x - 1, y - 1, f);
	check_angle(map, x - 1, y + 1, f);
	while (map[y][x] && map[y][x] == '-')
	{
		if (y != 0 && (map[y - 1][x] != '-' && map[y - 1][x] != '1'))
			exit_error_map(x, y - 1, f);
		if (y != f->map_max_y - 1 && \
			map[y + 1][x] != '-' && map[y + 1][x] != '1')
			exit_error_map(x, y + 1, f);
		x++;
	}
	check_angle(map, x, y, f);
	check_angle(map, x, y - 1, f);
	check_angle(map, x, y + 1, f);
	return (x);
}

void	walls(t_file *f, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < f->map_max_y)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '-')
				x = helper(x, y, map, f);
			else
				x++;
		}
		y++;
	}
}
