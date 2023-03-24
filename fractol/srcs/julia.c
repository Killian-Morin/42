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

void	ft_julia(t_data img)
{
	t_complex	c;
	t_complex	new;
	t_complex	old;
	int			i;
	int			x;
	int			y;

	c.re = 0.0;
	c.im = 0.3;
	x = 0;
	while (x++ != WIDTH)
	{
		y = 0;
		while (y++ != HEIGHT)
		{
			new.re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			new.im = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			i = 0;
			while (new.re * new.re + new.im * new.im <= 4 && i++ != MAX_ITER)
			{
				old.re = new.re;
				old.im = new.im;
				new.re = old.re * old.re - old.im * old.im + c.re;
				new.im = 2 * old.re * old.im + c.im;
			}
			if (i < MAX_ITER)
				my_mlx_pixel_put(&img, x, y, ft_color(i));
			else
				my_mlx_pixel_put(&img, x, y, 0x0);
		}
	}
}
