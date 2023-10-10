/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:46:26 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/09 13:59:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	function that simply exit while returning a int
	used in mlx_hook for the function that is called when closing the window
	use this one instead of exit() since the function used in mlx_hook has to
	return an int
*/
int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	keyboard_manager(int keycode, t_cub3d *data)
{
	(void)data;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void	hooks(t_cub3d *data)
{
	mlx_hook(data->win, EVENT_KEY_DOWN, 0, keyboard_manager, data);
	mlx_hook(data->win, EVENT_RED_CROSS, 0, ft_exit, 0);
}

/*
	to use instead of mlx_pixel_put | mimic its behaviour
	calculate the offset of the pixels to align them correctly
*/
void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_cub3d *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "test");
	if (!data->win)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_lenght, &data->endian);
	if (!data->addr)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_cub3d	*data;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_cub3d));
	if (!data)
		return (EXIT_FAILURE);
	init_mlx(data);
	int	y = 380;
	while (y != 440)
	{
		int	x = 482;
		while (x != 542)
		{
			my_mlx_pixel_put(data, x, y, 0xf8c95f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_mouse_move(data->win, WIDTH / 2, HEIGHT / 2);
	hooks(data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}
