/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:13 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/27 12:46:58 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
tentative exit qd player out of map (sans collision)
	if (BONUS == 0)
	{
		if (data->file.map[(int)data->p.pos_y][(int)data->p.pos_x] == '-' || \
			data->p.pos_x < 1 || data->p.pos_y > data->file.map_max_y - 1 || \
			data->p.pos_x > data->file.map_max_x - 1 || data->p.pos_y < 1)
			exit_routine(data, 3, 0);
	}
*/
void	move_up(t_cub3d *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->p.pos_x + data->p.dir_x * data->p.move_speed;
	new_pos_y = data->p.pos_y + data->p.dir_y * data->p.move_speed;
	if (check_collision(data, new_pos_x, new_pos_y) == true)
	{
		data->p.pos_x = new_pos_x;
		data->p.pos_y = new_pos_y;
	}
}

void	move_down(t_cub3d *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->p.pos_x - data->p.dir_x * data->p.move_speed;
	new_pos_y = data->p.pos_y - data->p.dir_y * data->p.move_speed;
	if (check_collision(data, new_pos_x, new_pos_y) == true)
	{
		data->p.pos_x = new_pos_x;
		data->p.pos_y = new_pos_y;
	}
}

void	move_right(t_cub3d *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->p.pos_x + data->p.plane_x * data->p.move_speed;
	new_pos_y = data->p.pos_y + data->p.plane_y * data->p.move_speed;
	if (check_collision(data, new_pos_x, new_pos_y) == true)
	{
		data->p.pos_x = new_pos_x;
		data->p.pos_y = new_pos_y;
	}
}

void	move_left(t_cub3d *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->p.pos_x - data->p.plane_x * data->p.move_speed;
	new_pos_y = data->p.pos_y - data->p.plane_y * data->p.move_speed;
	if (check_collision(data, new_pos_x, new_pos_y) == true)
	{
		data->p.pos_x = new_pos_x;
		data->p.pos_y = new_pos_y;
	}
}

void	move(t_cub3d *data, int keycode)
{
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	if (keycode == KEY_W)
		move_up(data);
	if (keycode == KEY_S)
		move_down(data);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	start(data);
}
