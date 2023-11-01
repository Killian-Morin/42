/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:15:37 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/30 15:42:17 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 * function: get_tex_num
 * texNum -> the index of the texture in the table data->t[4]
 * 0 = north	1 = south	2 = west	3 = east

 * wallX is the exact coordinate of x where of the ray hits a wall.
 */

int	get_tex_num(t_cub3d *data, double *wall_x)
{
	int	tex_num;

	if (data->wall.side == 0)
	{
		if (data->wall.ray_dir_x < 0)
			tex_num = 2;
		else
			tex_num = 3;
		*wall_x = data->p.pos_y;
		*wall_x += data->wall.perp_wall_dist * data->wall.ray_dir_y;
	}
	else
	{
		if (data->wall.ray_dir_y < 0)
			tex_num = 0;
		else
			tex_num = 1;
		*wall_x = data->p.pos_x;
		*wall_x += data->wall.perp_wall_dist * data->wall.ray_dir_x;
	}
	*wall_x = *wall_x - floor(*wall_x);
	return (tex_num);
}

/*
 * function: calculate_tex_x
 * data->wall.side == 0 && data->wall.ray_dir_x > 0) //  horizontal wall east
 * data->wall.side == 1 && data->wall.ray_dir_y < 0) //  vertical wall north
 */

int	calculate_tex_x(t_cub3d *data, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (data->wall.side == 0 && data->wall.ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (data->wall.side == 1 && data->wall.ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

/*
	tex_y is the result of a bitwise AND operation, its purpose it to hide
	the bits of tex_pos to ensure they stay within the range of TEX_HEIGHT - 1
*/

void	get_texture_color(t_cub3d *data, int tex_num, int tex_x, int x)
{
	int				y;
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;

	step = 1.0 * TEX_HEIGHT / data->wall.line_height;
	tex_pos = (data->wall.draw_start - HEIGHT / 2 + data->wall.line_height / 2);
	tex_pos *= step;
	y = data->wall.draw_start;
	while (y <= data->wall.draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = data->t[tex_num].addr[TEX_HEIGHT * tex_y + tex_x];
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

/*
 * function: texture_mapping
 * The pixel of the texture to be drawn on the wall is:
 * data->t[texNum][texX][texY],

 * We firstly find which texture we have to work with
 * depending on the directions.
 * texNum -> the index number of the texture I will use
 * 0 = no.xpm	1 = so.xpm	2 = we.xpm	3 = ea.xpm

 * Then we find the tex_x - the x coordinate of the texture.
 * From there we can copy the pixels all the way following a
 * vertical line in the y coordinate. This line starts at tex_y.
 */

void	texture_mapping(t_cub3d *data, int x)
{
	int				tex_num;
	int				tex_x;
	double			wall_x;

	tex_num = get_tex_num(data, &wall_x);
	tex_x = calculate_tex_x(data, wall_x);
	get_texture_color(data, tex_num, tex_x, x);
}
