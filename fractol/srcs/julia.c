/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_init(t_fractal *f)
{
	f->x_min = -2.0;
	f->x_max = 2.0;
	f->y_min = -2.0;
	f->y_max = 2.0;
	if (!ft_strncmp(f->name, "Julia1", 6))
	{
		f->c_re = -0.2321;
		f->c_im = -0.835;
	}
	else if (!ft_strncmp(f->name, "Julia2", 6))
	{
		f->c_re = -0.3842;
		f->c_im = -0.70176;
	}
	else
	{
		f->c_re = 0.285;
		f->c_im = 0.01;
	}
}

void	julia_iter(t_fractal *f)
{
	f->pixel_y = 0;
	while (f->pixel_y != HEIGHT)
	{
		f->pixel_x = 0;
		while (f->pixel_x != WIDTH)
		{
			f->nb_iter = 0;
			julia(f);
			f->pixel_x++;
		}
		f->pixel_y++;
	}
}

void	julia(t_fractal *f)
{
	f->re = 1.5 * (f->pixel_x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->move_x;
	f->im = (f->pixel_y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->move_y;
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
