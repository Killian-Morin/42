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
	int			col;
	int			row;

	col = 0;
	while (col++ != HEIGHT)
	{
		row = 0;
		while (row++ != WIDTH)
		{
			c.x = (col - WIDTH / 2.0) * 6.0 / WIDTH;
			c.y = (row - HEIGHT / 2.0) * 6.0 / WIDTH;
			z.x = 0;
			z.y = 0;
			i = 0;
			while ((z.x * z.x) + (z.y * z.y) <= 4 && i++ <= 100)
			{
				temp = (z.x * z.x) - (z.y * z.y) + c.x;
				z.y = (2 * z.x * z.y) + c.y;
				z.x = temp;
			}
			if (i < 100)
				my_mlx_pixel_put(&img, col, row, 0x0);
			else
				my_mlx_pixel_put(&img, col, row, 0xffd700);
		}
	}
}
