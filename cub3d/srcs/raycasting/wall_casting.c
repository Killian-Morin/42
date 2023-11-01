/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:13:33 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 16:02:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_casting_init(t_cub3d *data, int x)
{
	data->p.cam_x = 2 * x / (double) WIDTH - 1;
	data->wall.ray_dir_x = data->p.dir_x + data->p.plane_x * data->p.cam_x;
	data->wall.ray_dir_y = data->p.dir_y + data->p.plane_y * data->p.cam_x;
	data->wall.map_x = (int)data->p.pos_x;
	data->wall.map_y = (int)data->p.pos_y;
	if (data->wall.ray_dir_x == 0)
		data->wall.delta_x = 1e30;
	else
		data->wall.delta_x = fabs(1 / data->wall.ray_dir_x);
	if (data->wall.ray_dir_y == 0)
		data->wall.delta_y = 1e30;
	else
		data->wall.delta_y = fabs(1 / data->wall.ray_dir_y);
	data->wall.hit = 0;
}

void	wall_casting_side_dist(t_cub3d *data)
{
	if (data->wall.ray_dir_x < 0)
	{
		data->wall.step_x = -1;
		data->wall.side_x = (data->p.pos_x - data->wall.map_x) \
			* data->wall.delta_x;
	}
	else
	{
		data->wall.step_x = 1;
		data->wall.side_x = (data->wall.map_x + 1.0 - data->p.pos_x) \
			* data->wall.delta_x;
	}
	if (data->wall.ray_dir_y < 0)
	{
		data->wall.step_y = -1;
		data->wall.side_y = (data->p.pos_y - data->wall.map_y) \
			* data->wall.delta_y;
	}
	else
	{
		data->wall.step_y = 1;
		data->wall.side_y = (data->wall.map_y + 1.0 - data->p.pos_y) \
			* data->wall.delta_y;
	}
}

/*
	if (data->wall.map_y > data->file.map_max_y || \
		data->wall.map_x > data->file.map_max_x || \
		data->wall.map_x < 1 || data->wall.map_y < 1)
		exit_routine(data, 3, 0);

side = 0 -> means it met an horizontal wall
side = 1 -> means it met a vertical wall
*/
void	wall_casting_dda(t_cub3d *data)
{
	while (data->wall.hit == 0)
	{
		if (data->wall.side_x < data->wall.side_y)
		{
			data->wall.side_x += data->wall.delta_x;
			data->wall.map_x += data->wall.step_x;
			data->wall.side = 0;
		}
		else
		{
			data->wall.side_y += data->wall.delta_y;
			data->wall.map_y += data->wall.step_y;
			data->wall.side = 1;
		}
		if (data->file.map[data->wall.map_y][data->wall.map_x] == '1')
			data->wall.hit = 1;
	}
}

void	wall_casting_wall_height(t_cub3d *data)
{
	if (data->wall.side == 0)
		data->wall.perp_wall_dist = (data->wall.side_x - data->wall.delta_x);
	else
		data->wall.perp_wall_dist = (data->wall.side_y - data->wall.delta_y);
	data->wall.line_height = (int)(HEIGHT / data->wall.perp_wall_dist);
	data->wall.draw_start = -(data->wall.line_height) / 2 + HEIGHT / 2;
	if (data->wall.draw_start < 0)
		data->wall.draw_start = 0;
	data->wall.draw_end = data->wall.line_height / 2 + HEIGHT / 2;
	if (data->wall.draw_end >= HEIGHT)
		data->wall.draw_end = HEIGHT - 1;
}

void	wall_casting(t_cub3d *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		wall_casting_init(data, x);
		wall_casting_side_dist(data);
		wall_casting_dda(data);
		wall_casting_wall_height(data);
		texture_mapping(data, x);
		x++;
	}
}
