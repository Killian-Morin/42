/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:18:56 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/27 15:20:15 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int x, int y, t_cub3d *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	(void)y;
	if (data->p.mouse_lock == 1 && BONUS == 1)
	{
		if (x < WIDTH / 2)
			speed = data->p.rot_speed * -0.5;
		else
			speed = data->p.rot_speed * 0.5;
		old_dir_x = data->p.dir_x;
		data->p.dir_x = data->p.dir_x * cos(speed) - data->p.dir_y * sin(speed);
		data->p.dir_y = old_dir_x * sin(speed) + data->p.dir_y * cos(speed);
		old_plane_x = data->p.plane_x;
		data->p.plane_x = data->p.plane_x * cos(speed) - data->p.plane_y * \
			sin(speed);
		data->p.plane_y = old_plane_x * sin(speed) + data->p.plane_y * \
			cos(speed);
		mlx_clear_window(data->mlx->mlx, data->mlx->win);
		start(data);
	}
	return (0);
}
