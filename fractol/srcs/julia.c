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
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
	f->mouse_lock = 0;
	if (!ft_strncmp(f->name, "Julia1", 6))
	{
		f->c_re = -0.203333;
		f->c_im = -0.696667;
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
	f->pxl_y = 0;
	while (f->pxl_y != HEIGHT)
	{
		f->pxl_x = 0;
		while (f->pxl_x != WIDTH)
		{
			julia(f);
			f->pxl_x++;
		}
		f->pxl_y++;
	}
}

void	julia(t_fractal *f)
{
	f->nb_iter = 0;
	f->re = 1.5 *((f->pxl_x / WIDTH) * (f->max_re - f->min_re)) * f->zoom + f->min_re + f->move_x;
	// f->re = 1.5 * (f->pxl_x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->move_x;
	f->im = ((f->pxl_y / HEIGHT) * (f->max_im - f->min_im)) * f->zoom + f->min_im + f->move_y;
	// f->im = (f->pxl_y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->move_y;
	while (f->re * f->re + f->im * f->im < 4 && f->nb_iter != f->max_iter)
	{
		f->temp = f->re * f->re - f->im * f->im + f->c_re;
		f->im = 2 * f->re * f->im + f->c_im;
		f->re = f->temp;
		f->nb_iter++;
	}
	if (f->nb_iter < f->max_iter)
		my_mlx_pixel_put(f, f->pxl_x, f->pxl_y, ft_color(f->nb_iter));
	else
		my_mlx_pixel_put(f, f->pxl_x, f->pxl_y, 0x0);
}
