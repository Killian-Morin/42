/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:47:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/26 14:53:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_north_direction(t_player *p)
{
	p->plane_x = 0.66;
	p->plane_y = 0;
	p->dir_x = 0;
	p->dir_y = -1;
}

void	init_south_direction(t_player *p)
{
	p->plane_x = -0.66;
	p->plane_y = 0;
	p->dir_x = 0;
	p->dir_y = 1;
}

void	init_east_direction(t_player *p)
{
	p->plane_x = 0;
	p->plane_y = 0.66;
	p->dir_x = 1;
	p->dir_y = 0;
}

void	init_west_direction(t_player *p)
{
	p->plane_x = 0;
	p->plane_y = -0.66;
	p->dir_x = -1;
	p->dir_y = 0;
}

int	is_on_player(t_player *p, char c)
{
	if (c == 'N')
	{
		init_north_direction(p);
		return (1);
	}
	else if (c == 'S')
	{
		init_south_direction(p);
		return (1);
	}
	else if (c == 'E')
	{
		init_east_direction(p);
		return (1);
	}
	else if (c == 'W')
	{
		init_west_direction(p);
		return (1);
	}
	return (0);
}
