/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:26 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/31 09:45:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
use those functions calls to use the lodev algorithm for the floor and ceiling
	floor_casting(data);
	ceiling_casting(data);

decided to not hide the mouse when beginning the window
*/
void	start(t_cub3d *data)
{
	floor_ceiling_casting(data);
	wall_casting(data);
	if (BONUS == 1)
		minimap(data);
	mlx_mouse_move(data->mlx->win, WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, \
		0, 0);
}

void	init_var(t_cub3d *data)
{
	data->p.move_speed = 0.09;
	data->p.rot_speed = 0.05;
	data->p.mouse_lock = 0;
}

int	main(int ac, char **av)
{
	t_cub3d	data;
	t_list	*head;

	if (ac != 2)
		error_exit("Not the right amount of arguments, need a .cub file\n", 0);
	head = NULL;
	data.mlx_text = &(t_mlx){};
	data.mlx = &(t_mlx){};
	data.file = (t_file){};
	parser(&data, av[1], head);
	init_textures(&data);
	init_mlx(&data);
	init_var(&data);
	start(&data);
	explanation_text();
	hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
