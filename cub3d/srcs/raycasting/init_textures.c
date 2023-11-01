/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:05:26 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/30 15:36:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	new_window(t_cub3d *data)
{
	data->mlx_text->mlx = mlx_init();
	data->mlx_text->win = mlx_new_window(data->mlx_text->mlx, TEX_WIDTH, \
		TEX_HEIGHT, "textures");
	data->mlx_text->img = mlx_new_image(data->mlx_text->mlx, TEX_WIDTH, \
		TEX_HEIGHT);
	if (!data->mlx_text->mlx || !data->mlx_text->win || !data->mlx_text->img)
		exit_routine(data, 2, 1);
}

void	get_textures_address(t_cub3d *data, int i, t_mlx *mlx_text)
{
	int		*width;
	int		*height;

	width = &data->t[i].width;
	height = &data->t[i].height;
	if (i == 0)
		mlx_text->img = mlx_xpm_file_to_image(mlx_text->mlx, data->file.no_tex, \
			width, height);
	else if (i == 1)
		mlx_text->img = mlx_xpm_file_to_image(mlx_text->mlx, data->file.so_tex, \
			width, height);
	else if (i == 2)
		mlx_text->img = mlx_xpm_file_to_image(mlx_text->mlx, data->file.we_tex, \
			width, height);
	else if (i == 3)
		mlx_text->img = mlx_xpm_file_to_image(mlx_text->mlx, data->file.ea_tex, \
			width, height);
	if (!mlx_text->img)
		exit_routine(data, 4, 1);
	mlx_put_image_to_window(mlx_text->mlx, data->mlx_text->win, mlx_text->img, \
		TEX_WIDTH, TEX_HEIGHT);
	data->t[i].addr = (int *)mlx_get_data_addr(mlx_text->img, \
	&data->t[i].bits_per_pixel, &data->t[i].line_length, &data->t[i].endian);
}

/*
	might not need the mlx_destroy_image since each window is cleared before
	removed and it causes a texture bug for the last texture put to image
*/
void	init_textures(t_cub3d *data)
{
	int	i;

	data->t = malloc(sizeof(t_texture) * 4);
	if (!data->t)
		error_exit("malloc failed in init_textures()\n", 1);
	new_window(data);
	i = 0;
	while (i < 4)
	{
		get_textures_address(data, i, data->mlx_text);
		mlx_clear_window(data->mlx_text->mlx, data->mlx_text->win);
		i++;
	}
	mlx_destroy_window(data->mlx_text->mlx, data->mlx_text->win);
}
