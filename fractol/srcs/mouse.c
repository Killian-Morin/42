/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_zoom(int mousecode, t_f *p)
{
	if (mousecode == 4 || mousecode == 5)
	{
		if (mousecode == 4)
			p->zoom *= 0.8;
		else
			p->zoom /= 0.8;
		mlx_clear_window(p->mlx, p->win);
		if (!ft_strncmp(p->name, "Mandelbrot", 11))
			ft_mandelbrot_start(p);
		if (!ft_strncmp(p->name, "Julia", 5))
			ft_julia_start(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	return (0);
}

int	ft_change_julia(t_f *p)
{
	if (!ft_strncmp(p->name, "Julia", 5))
	{
		p->c_re += 0.01;
		p->c_im += 0.01;
		mlx_clear_window(p->mlx, p->win);
		p->y = 0;
		while (p->y != HEIGHT)
		{
			p->x = 0;
			while (p->x != WIDTH)
			{
				p->nb_iter = 0;
				ft_julia(p);
				p->x++;
			}
			p->y++;
		}
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	return (0);
}
