/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:18:11 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 13:25:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_horizontal_grid(t_cub3d *data, int x_, int y_)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = x_ * SQUARE_SIZE_2;
	y = y_ * SQUARE_SIZE_2;
	if (data->file.map[y_][x_] != ' ')
	{
		while (i < SQUARE_SIZE_2)
		{
			my_mlx_pixel_put(data, x + i, y + 0, 0xffffff);
			my_mlx_pixel_put(data, x + i, y + SQUARE_SIZE_2, 0xffffff);
			i++;
		}
		my_mlx_pixel_put(data, x + i, y + SQUARE_SIZE_2, 0xffffff);
	}
}

void	draw_vertical_grid(t_cub3d *data, int x_, int y_)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = x_ * SQUARE_SIZE_2;
	y = y_ * SQUARE_SIZE_2;
	if (data->file.map[y_][x_] != ' ')
	{
		while (i < SQUARE_SIZE_2)
		{
			my_mlx_pixel_put(data, x + 0, y + i, 0xffffff);
			my_mlx_pixel_put(data, x + SQUARE_SIZE_2, y + i, 0xffffff);
			i++;
		}
	}
}

void	draw_grid(t_cub3d *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->file.map[y])
	{
		x = 0;
		while (data->file.map[y][x])
		{
			draw_horizontal_grid(data, x, y);
			draw_vertical_grid(data, x, y);
			x++;
		}
		y++;
	}
}
