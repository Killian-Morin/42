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

void	ft_mandelbrot(t_data img)
{
	t_complex	c;
	t_complex	z;
	double		temp;
	int			i;
	t_pos		pos;

	pos.x = 0;
	pos.zoom = 0.8;
	while (pos.x++ != WIDTH)
	{
		pos.y = 0;
		while (pos.y++ != HEIGHT)
		{
			c.re = 1.5 * (pos.x - WIDTH / 2) / (0.5 * pos.zoom * WIDTH);
			c.im = (pos.y - HEIGHT / 2) / (0.5 * pos.zoom * HEIGHT);
			z.re = 0;
			z.im = 0;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i++ != MAX_ITER)
			{
				temp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = temp;
			}
			if (i < MAX_ITER)
				my_mlx_pixel_put(&img, pos.x, pos.y, ft_color(i));
			else
				my_mlx_pixel_put(&img, pos.x, pos.y, 0x0);
		}
	}
}
