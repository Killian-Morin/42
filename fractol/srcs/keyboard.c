/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_keyboard(int keycode, t_f *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 123)
		p->move_x -= 2.0;
	if (keycode == 124)
		p->move_x += 2.0;
	if (keycode == 125)
		p->move_y -= 2.0;
	if (keycode == 126)
		p->move_y += 2.0;
	return (0);
}

/*
int ft_keyboard(int keycode, t_vars *vars)
{
    if (keycode == 0)//a
        changer le c.re de julia
    if (keycode == 2)//d
        changer le c.im de julia
	if (keycode == 69)
		pos.zoom += 0.5;
	if (keycode == 78)
		pos.zoom -= 0.5;
    return (0);
}*/
