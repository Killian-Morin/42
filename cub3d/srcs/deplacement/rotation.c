/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:20 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 16:36:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_cub3d *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	speed = data->p.rot_speed * -1;
	old_dir_x = data->p.dir_x;
	data->p.dir_x = data->p.dir_x * cos(speed) - data->p.dir_y * sin(speed);
	data->p.dir_y = old_dir_x * sin(speed) + data->p.dir_y * cos(speed);
	old_plane_x = data->p.plane_x;
	data->p.plane_x = data->p.plane_x * cos(speed) - data->p.plane_y * \
		sin(speed);
	data->p.plane_y = old_plane_x * sin(speed) + data->p.plane_y * cos(speed);
}

void	rotate_right(t_cub3d *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	speed = data->p.rot_speed;
	old_dir_x = data->p.dir_x;
	data->p.dir_x = data->p.dir_x * cos(speed) - data->p.dir_y * sin(speed);
	data->p.dir_y = old_dir_x * sin(speed) + data->p.dir_y * cos(speed);
	old_plane_x = data->p.plane_x;
	data->p.plane_x = data->p.plane_x * cos(speed) - data->p.plane_y * \
		sin(speed);
	data->p.plane_y = old_plane_x * sin(speed) + data->p.plane_y * cos(speed);
}

void	rotate(t_cub3d *data, int keycode)
{
	if (keycode == ARROW_LEFT)
		rotate_left(data);
	else
		rotate_right(data);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	start(data);
}
