/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_casting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:06:16 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/25 15:12:51 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	LODEV METHOD FOR FLOOR AND CEILING CASTING

void	floor_casting_line(t_cub3d *data, int y)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		my_mlx_pixel_put(data, x, y, data->file.ceiling_color);
		++x;
	}
}

void	floor_casting(t_cub3d *data)
{
	int	y;
	int	p;

	y = HEIGHT / 2 + 1;
	while (y > 0)
	{
		data->f_c.ray_dir_x0 = data->p.dir_x - data->p.plane_x;
		data->f_c.ray_dir_y0 = data->p.dir_y - data->p.plane_y;
		data->f_c.ray_dir_x1 = data->p.dir_x + data->p.plane_x;
		data->f_c.ray_dir_y1 = data->p.dir_y + data->p.plane_y;
		p = y - HEIGHT / 2;
		data->f_c.cam_z_pos = 0.5 * HEIGHT;
		data->f_c.row_distance = data->f_c.cam_z_pos / p;
		data->f_c.floor_step_x = data->f_c.row_distance * \
			(data->f_c.ray_dir_x1 - data->f_c.ray_dir_x0) / WIDTH;
		data->f_c.floor_step_y = data->f_c.row_distance * \
			(data->f_c.ray_dir_y1 - data->f_c.ray_dir_y0) / WIDTH;
		data->f_c.floor_x = data->p.pos_x + data->f_c.row_distance * \
			data->f_c.ray_dir_x0;
		data->f_c.floor_y = data->p.pos_y + data->f_c.row_distance * \
			data->f_c.ray_dir_y0;
		floor_casting_line(data, y);
		--y;
	}
}

void	ceiling_casting_line(t_cub3d *data, int y)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		my_mlx_pixel_put(data, x, y, data->file.floor_color);
		++x;
	}
}

void	ceiling_casting(t_cub3d *data)
{
	int	y;
	int	p;

	y = HEIGHT / 2 + 1;
	while (y < HEIGHT)
	{
		data->f_c.ray_dir_x0 = data->p.dir_x - data->p.plane_x;
		data->f_c.ray_dir_y0 = data->p.dir_y - data->p.plane_y;
		data->f_c.ray_dir_x1 = data->p.dir_x + data->p.plane_x;
		data->f_c.ray_dir_y1 = data->p.dir_y + data->p.plane_y;
		p = y - HEIGHT / 2;
		data->f_c.cam_z_pos = 0.5 * HEIGHT;
		data->f_c.row_distance = data->f_c.cam_z_pos / p;
		data->f_c.floor_step_x = data->f_c.row_distance * \
			(data->f_c.ray_dir_x1 - data->f_c.ray_dir_x0) / WIDTH;
		data->f_c.floor_step_y = data->f_c.row_distance * \
			(data->f_c.ray_dir_y1 - data->f_c.ray_dir_y0) / WIDTH;
		data->f_c.floor_x = data->p.pos_x + data->f_c.row_distance * \
			data->f_c.ray_dir_x0;
		data->f_c.floor_y = data->p.pos_y + data->f_c.row_distance * \
			data->f_c.ray_dir_y0;
		ceiling_casting_line(data, y);
		++y;
	}
}
*/

void	floor_ceiling_casting(t_cub3d *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y <= HEIGHT / 2)
			my_mlx_pixel_put(data, x, y++, data->file.ceiling_color);
		while (y < HEIGHT)
			my_mlx_pixel_put(data, x, y++, data->file.floor_color);
		x++;
	}
}
