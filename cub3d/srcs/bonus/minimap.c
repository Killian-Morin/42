/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:07:29 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/30 15:40:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_cub3d *data, int color, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	x = x * SQUARE_SIZE_2;
	y = y * SQUARE_SIZE_2;
	while (i < SQUARE_SIZE_2)
	{
		j = 0;
		while (j < SQUARE_SIZE_2)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_cub3d *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x])
		{
			if (data->file.map[y][x] == '1' || data->file.map[y][x] == '-')
				draw(data, 0x0, x, y);
			else if (data->file.map[y][x] != ' ')
				draw(data, 0xd3d3d3, x, y);
			x++;
		}
		y++;
	}
}

/*
void	save_rays_dist(t_cub3d *data, int column)
{
	data->minimap->dist[column] = (data->wall.perp_wall_dist / SQUARE_SIZE) * \
		SQUARE_SIZE_2;
	data->minimap->ang[column] = 60;
}*/

/*
	the code is from Mariya
	not used draw_grid() but kept the file (minimap_grid.c)
	was not able to make it works with this version of raycasting
	draw_rays_minimap() and draw_direction_line()
	so didn't put them here but the functions are in minimap_rays.c

	would need to call set_player_attributes before wall_casting() and put
	save_rays_dist in the while loop of it
*/
void	minimap(t_cub3d *data)
{
	data->minimap = &(t_minimap){};
	set_player_attributes(data, data->minimap);
	draw_map(data);
	draw_player(data, data->minimap);
	free(data->minimap->dist);
	data->minimap->dist = NULL;
	free(data->minimap->ang);
	data->minimap->ang = NULL;
}
