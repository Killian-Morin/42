/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot_start(t_f *p)
{
	p->y = 0;
	while (p->y != HEIGHT)
	{
		p->x = 0;
		while (p->x != WIDTH)
		{
			p->nb_iter = 0;
			p->re = 0;
			p->im = 0;
			ft_mandelbrot(p);
			p->x++;
		}
		p->y++;
	}
}

void	ft_mandelbrot(t_f *p)
{
	p->c_re = 1.5 * (p->x - WIDTH / 2) / (0.5 * p->zoom * WIDTH) + p->move_x;
	p->c_im = (p->y - HEIGHT / 2) / (0.5 * p->zoom * HEIGHT) + p->move_y;
	while (p->re * p->re + p->im * p->im <= 4 && p->nb_iter != p->max_iter)
	{
		p->temp = p->re * p->re - p->im * p->im + p->c_re;
		p->im = 2 * p->re * p->im + p->c_im;
		p->re = p->temp;
		p->nb_iter++;
	}
	if (p->nb_iter < p->max_iter)
		my_mlx_pixel_put(p, p->x, p->y, ft_color(p->nb_iter));
	else
		my_mlx_pixel_put(p, p->x, p->y, 0x0);
}
