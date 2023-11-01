/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:41:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/30 14:27:53 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walls_checker_top(t_file *f)
{
	int	x;

	x = 0;
	while (x != f->map_max_x)
	{
		if (f->map[0][x] == '1' || f->map[0][x] == '-')
			x++;
		else
		{
			free_tab_size(f->map, f->map_max_y);
			free_texture_file(f);
			error_msg_exit("Map error:", \
				"Map is not closed by walls on top");
		}
	}
}

void	walls_checker_left(t_file *f)
{
	int	y;

	y = 0;
	while (y != f->map_max_y)
	{
		if (f->map[y][0] == '1' || f->map[y][0] == '-')
			y++;
		else
		{
			free_tab_size(f->map, f->map_max_y);
			free_texture_file(f);
			error_msg_exit("Map error:", \
				"Map is not closed by walls on left side");
		}
	}
}

void	walls_checker_bottom(t_file *f)
{
	int	x;

	x = 0;
	while (x != f->map_max_x)
	{
		if (f->map[f->map_max_y - 1][x] == '1' || \
			f->map[f->map_max_y - 1][x] == '-')
			x++;
		else
		{
			free_tab_size(f->map, f->map_max_y);
			free_texture_file(f);
			error_msg_exit("Map error:", \
				"Map is not closed by walls on bottom");
		}
	}
}

void	walls_checker_right(t_file *f)
{
	int	y;

	y = 0;
	while (y != f->map_max_y)
	{
		if (f->map[y][f->map_max_x - 1] == '1' || \
			f->map[y][f->map_max_x - 1] == '-')
			y++;
		else
		{
			free_tab_size(f->map, f->map_max_y);
			free_texture_file(f);
			error_msg_exit("Map error:", \
				"Map is not closed by walls on right side");
		}
	}
}

void	walls_checker(t_file *f)
{
	walls_checker_top(f);
	walls_checker_left(f);
	walls_checker_bottom(f);
	walls_checker_right(f);
	walls(f, f->map);
}
