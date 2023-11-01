/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:44:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/30 15:37:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	to use instead of mlx_pixel_put | mimic its behaviour
	calculate the offset of the pixels to align them correctly
*/
void	my_mlx_pixel_put(t_cub3d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mlx->addr + (y * d->mlx->line_lenght + x * \
		(d->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	hooks(t_cub3d *data)
{
	mlx_hook(data->mlx->win, KEY_PRESS, 0, keyboard_manager, data);
	mlx_hook(data->mlx->win, RED_CROSS, 0, ft_exit, data);
	mlx_hook(data->mlx->win, MOUSE_MOVE, 0, ft_mouse, data);
}

/*
not necessary
	data->mlx = &(t_mlx){};
	data->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!data->mlx)
		error_exit("ft_calloc failed in init_mlx()\n", 1);
*/
void	init_mlx(t_cub3d *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_routine(data, 2, 1);
	data->mlx->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	if (!data->mlx->win)
		exit_routine(data, 2, 1);
	data->mlx->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->mlx->img)
		exit_routine(data, 2, 1);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, & \
		data->mlx->bits_per_pixel, &data->mlx->line_lenght, &data->mlx->endian);
	if (!data->mlx->addr)
		exit_routine(data, 2, 1);
}
