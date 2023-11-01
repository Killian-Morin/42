/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:49:09 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/31 09:41:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	tentative de slide
void	check_collision_slide(t_cub3d *data, double old_pos_x, double old_pos_y)
{
	double	diff_x;
	double	diff_y;
	int		step;

	if (data->file.map[(int)data->p.pos_y][(int)data->p.pos_x] == '1')
	{
		diff_x = data->p.pos_x - old_pos_x;
		diff_y = data->p.pos_y - old_pos_y;
		if (diff_x != 0)
		{
			if (diff_x > 0)
				step = 1;
			else
				step = -1;
			if (data->file.map[(int)data->p.pos_y][(int)data->p.pos_x + step] != '1')
				data->p.pos_x = old_pos_x;
		}
		if (diff_y != 0)
		{
			if (diff_y > 0)
				step = 1;
			else
				step = -1;
			if (data->file.map[(int)data->p.pos_y + step][(int)data->p.pos_x] != '1')
				data->p.pos_y = old_pos_y;
		}
	}
}
*/

/*
	autre piste pour collision
bool	boundaries_left_right_exit(t_cub3d *data)
{
	size_t	last_wall;
	size_t	first_wall;


	first_wall = ft_strlen(data->file.map[(int)data->p.pos_y]) - \
		ft_strlen(ft_strchr(data->file.map[(int)data->p.pos_y], '1'));
	last_wall = ft_strlen(data->file.map[(int)data->p.pos_y]) - \
		ft_strlen(ft_strrchr(data->file.map[(int)data->p.pos_y], '1'));

	printf("pox x =			%f	%d\n", data->p.pos_x, (int)data->p.pos_x);
	printf("first_wall =	%zu	%f\n", first_wall, (double)first_wall);
	printf("last_wall =		%zu	%f\n", last_wall, (double)last_wall);

	if (data->p.pos_x <= 1.0 || data->p.pos_x >= (double)data->file.map_max_x)
		return (true);
	if ((int)data->p.pos_x <= (int) first_wall)
		return (true);
	if ((int)data->p.pos_x >= (int) last_wall)
		return (true);
	return (false);
}

bool	space_exit(t_cub3d *data)
{
	if (data->file.map[(int)data->p.pos_y][(int)data->p.pos_x] == '-')
		return (true);
	return (false);
}

void	boundaries_up_down_exit(t_cub3d *data)
{
	if (data->p.pos_y)
}

bool	exit_check(t_cub3d *data)
{

	if (boundaries_left_right_exit(data) == true)
		return (true);
	// if (boundaries_up_down_exit(data) == false)
		// return (true);
	if (space_exit(data) == true)
		return (true);
	return (false);
}*/

/*
tentative pour collision que avec les murs exterieurs marche pas (segfault)
	if (new_pos_x > 0 && new_pos_x < data->file.map_max_x && \
		new_pos_y > 0 && new_pos_y < data->file.map_max_y)


no use since collision even without bonus
	if (BONUS)
	{
		if (data->file.map[(int)new_pos_y][(int)new_pos_x] == '1')
			ret = false;
	}
*/
bool	check_collision(t_cub3d *data, double new_pos_x, double new_pos_y)
{
	bool	ret;

	ret = false;
	if (data->file.map[(int)new_pos_y][(int)new_pos_x] != '1' \
		&& data->file.map[(int)new_pos_y][(int)new_pos_x] != '-')
		ret = true;
	return (ret);
}
