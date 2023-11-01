/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:28:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 14:56:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_attributes(t_cub3d *data, t_minimap *minimap)
{
	minimap->fov = 60 / 57.29578;
	minimap->x = data->p.pos_x;
	minimap->y = data->p.pos_y;
	minimap->x_pixel = minimap->x * SQUARE_SIZE;
	minimap->y_pixel = minimap->y * SQUARE_SIZE;
	minimap->dist = malloc(sizeof(double) * WIDTH);
	minimap->ang = malloc(sizeof(double) * WIDTH);
}

void	draw_player(t_cub3d *data, t_minimap *minimap)
{
	int	i;
	int	j;
	int	x_start;
	int	y_start;

	x_start = minimap->x * SQUARE_SIZE_2 - ((SQUARE_SIZE_2 / 4) / 2);
	y_start = minimap->y * SQUARE_SIZE_2 - ((SQUARE_SIZE_2 / 4) / 2);
	i = x_start;
	while (i < x_start + SQUARE_SIZE_2 / 4)
	{
		j = y_start;
		while (j < y_start + SQUARE_SIZE_2 / 4)
		{
			my_mlx_pixel_put(data, i, j, 0xff0000);
			j++;
		}
		i++;
	}
}
