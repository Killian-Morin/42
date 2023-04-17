/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_fractal *f)
{
	f->zoom = 0.7;
	f->move_x = 0;
	f->move_y = 0.6;
}

void	mandelbrot_iter(t_fractal *f)
{
	f->pxl_y = 0;
	while (f->pxl_y != HEIGHT)
	{
		f->pxl_x = 0;
		while (f->pxl_x != WIDTH)
		{
			mandelbrot(f);
			f->pxl_x++;
		}
		f->pxl_y++;
	}
}

void	mandelbrot(t_fractal *f)
{
	f->nb_iter = 0;
	f->re = ((f->pxl_x / WIDTH) * (f->max_re - f->min_re))
		* f->zoom + f->min_re + f->move_x;
	f->im = ((f->pxl_y / HEIGHT) * (f->max_im - f->min_im))
		* f->zoom + f->min_im + f->move_y;
	f->c_re = ((f->pxl_x / WIDTH) * (f->max_re - f->min_re))
		* f->zoom + f->min_re + f->move_x;
	f->c_im = ((f->pxl_y / HEIGHT) * (f->max_im - f->min_im))
		* f->zoom + f->min_im + f->move_y;
	while (f->re * f->re + f->im * f->im < 4 && f->nb_iter != f->max_iter)
	{
		f->temp = f->re * f->re - f->im * f->im + f->c_re;
		f->im = 2 * f->re * f->im + f->c_im;
		f->re = f->temp;
		f->nb_iter++;
	}
	if (f->nb_iter < f->max_iter)
		my_mlx_pixel_put(f, f->pxl_x, f->pxl_y, ft_determine_color(f));
	else
		my_mlx_pixel_put(f, f->pxl_x, f->pxl_y, 0x0);
}
