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
/*
void	ft_mandelbrot(t_data img)
{
	int	A = 0;
	int	B = 0;
	int	a;
	int	b;
	int	i;
	int	color;
	int	temp;
	t_complex	z;

	while (B++ <= 4 * 15)
	{
		b = 2 - (B / 15);
		while (A++ <= 4 * 15)
		{
			a = -2 + (A / 15);
			z.x = 0;
			z.y = 0;
			i = 1;
			while (i++ != 100)
			{
				temp = z.x;
				z.x = (z.x * z.x) - (z.y * z.y) + a;
				z.y = (2 * temp * z.y) + b;
				if ((z.x * z.x) + (z.y * z.y) > 4)
					break;
			}
			if (i == 100)
				color = 0x0;
			else
				color = 0xff;
			my_mlx_pixel_put(&img, z.x, z.y, color);
		}
	}
}*/
/*
void	ft_mandelbrot(t_data img)
{
	int	x;
	int	y;
	int	complex;
	int	color;
	int	z;
	int	n;

	x = 0;
	y = 0;
	while (x++ != WIDTH && y++ != HEIGHT)
	{
		complex = 
		z = 0;
		n = 0;
		while (n != 100 && ft_absolute(z) <= 2)
		{
			z = z*z + complex;
			n++;
		}
		color = 255 - (n * 255 / 100);
		my_mlx_pixel_put(&img, x, y, color);
	}
}*/

void	ft_mandelbrot(t_data img)
{
	t_complex	z;
	int		i;
	int		color;
	double	temp;
	int		a;
	int		b;

	a = 0;
	while (a++ != HEIGHT)
	{
		b = 0;
		while (b++ != WIDTH)
		{
			z.x = 0;
			z.y = 0;
			i = 1;
			while ((z.x * z.x) + (z.y * z.y) != 4 && i++ != 100)
			{
				temp = z.x;
				z.x = (z.x * z.x) - (z.y * z.y) + z.x;
				z.y = (2 * temp * z.y) + z.y;
			}
			if (i == 100)
				color = 0x0;
			color = 0xfffafa;
			my_mlx_pixel_put(&img, z.x, z.y, color);
		}
	}
}
