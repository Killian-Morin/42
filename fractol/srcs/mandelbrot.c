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

void	ft_mandelbrot_start(t_fractal *f)
{
	f->pixel_y = 0;
	while (f->pixel_y != HEIGHT)
	{
		f->pixel_x = 0;
		while (f->pixel_x != WIDTH)
		{
			f->nb_iter = 0;
			f->re = 0;
			f->im = 0;
			ft_mandelbrot(f);
			f->pixel_x++;
		}
		f->pixel_y++;
	}
}

void	ft_mandelbrot(t_fractal *f)
{
	f->c_re = 1.5 * (f->pixel_x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->move_x;
	f->c_im = (f->pixel_y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->move_y;
	while (f->re * f->re + f->im * f->im <= 4 && f->nb_iter != f->max_iter)
	{
		f->temp = f->re * f->re - f->im * f->im + f->c_re;
		f->im = 2 * f->re * f->im + f->c_im;
		f->re = f->temp;
		f->nb_iter++;
	}
	if (f->nb_iter < f->max_iter)
		my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, ft_color(f->nb_iter));
	else
		my_mlx_pixel_put(f, f->pixel_x, f->pixel_y, 0x0);
}
