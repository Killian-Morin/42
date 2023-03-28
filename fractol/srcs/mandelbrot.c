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

void	ft_mandelbrot(t_f *p)
{
	double		temp;
	int			i;

	p->x = 0;
	p->move_x = 0;
	p->move_y = 0;
	while (p->x++ != WIDTH)
	{
		p->y = 0;
		while (p->y++ != HEIGHT)
		{
			p->c_re = 1.5 * (p->x - WIDTH / 2) / (0.5 * p->zoom * WIDTH) + p->move_x;
			p->c_im = (p->y - HEIGHT / 2) / (0.5 * p->zoom * HEIGHT) + p->move_y;
			p->re = 0;
			p->im = 0;
			i = 0;
			while (p->re * p->re + p->im * p->im <= 4 && i++ != MAX_ITER)
			{
				temp = p->re * p->re - p->im * p->im + p->c_re;
				p->im = 2 * p->re * p->im + p->c_im;
				p->re = temp;
			}
			if (i < MAX_ITER)
				my_mlx_pixel_put(p, p->x, p->y, ft_color(i));
			else
				my_mlx_pixel_put(p, p->x, p->y, 0x0);
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
