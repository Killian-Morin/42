/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:01:37 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 16:01:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bresenhams_line_algorithm(t_cub3d *data, t_draw_line *line, int color)
{
	int	decision_param_1;
	int	decision_param_2;

	decision_param_1 = line->delta_x + line->delta_y;
	while (1)
	{
		my_mlx_pixel_put(data, line->x_start, line->y_start, color);
		if (line->x_start == line->x_end && line->y_start == line->y_end)
			break ;
		decision_param_2 = 2 * decision_param_1;
		if (decision_param_2 >= line->delta_y)
		{
			decision_param_1 += line->delta_y;
			line->x_start += line->increment_x;
		}
		if (decision_param_2 <= line->delta_x)
		{
			decision_param_1 += line->delta_x;
			line->y_start += line->increment_y;
		}
	}
}

void	draw_mini_line(t_cub3d *data, double line_length, double angle)
{
	t_draw_line	*line;

	line = &(t_draw_line){};
	line->x_start = (int)(data->minimap->x * SQUARE_SIZE_2);
	line->y_start = (int)(data->minimap->y * SQUARE_SIZE_2);
	line->x_end = (int)(line->x_start + line_length * cos(angle));
	line->y_end = (int)(line->y_start + line_length * sin(angle));
	line->delta_x = abs(line->x_end - line->x_start);
	line->delta_y = -abs(line->y_end - line->y_start);
	if (line->x_start < line->x_end)
		line->increment_x = 1;
	else
		line->increment_x = -1;
	if (line->y_start < line->y_end)
		line->increment_y = 1;
	else
		line->increment_y = -1;
	bresenhams_line_algorithm(data, line, 0xff00ff);
}

void	draw_rays_minimap(t_cub3d *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_mini_line(data, data->minimap->dist[i], data->minimap->ang[i]);
		i++;
	}
}

/* 
	to draw a line of 10 pixels showing where the player look
void	draw_direction_line(t_cub3d *data)
{
	data->minimap->color = 0x0000FF;
	data->minimap->line = &((t_draw_line){});
	draw_mini_line(data, data->minimap, 10, data->p.angle);
}*/
