/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:30:13 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 16:35:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
used in mlx_hook for the event of closing the window with the red cross
it is necessary that the function returns an int,
in order to be used in mlx_hook
*/
int	ft_exit(t_cub3d *data)
{
	exit_routine(data, 0, 0);
	return (0);
}

int	keyboard_manager(int keycode, t_cub3d *data)
{
	if (keycode == ESC)
		exit_routine(data, 1, 0);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_D || \
		keycode == KEY_A)
		move(data, keycode);
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		rotate(data, keycode);
	if (keycode == KEY_P)
		mlx_mouse_show();
	if (keycode == KEY_H)
		mlx_mouse_hide();
	if (keycode == KEY_R)
	{
		get_player_direction(data->file.map, &data->p);
		start(data);
	}
	if (keycode == KEY_M && data->p.mouse_lock == 0)
		data->p.mouse_lock = 1;
	else if (keycode == KEY_M && data->p.mouse_lock == 1)
		data->p.mouse_lock = 0;
	return (0);
}
