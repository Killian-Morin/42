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
	t_pos		pos;

	c.re = -0.5;
	c.im = 0.6;
	pos.x = 0;
	pos.zoom = 0.7;
	while (pos.x++ != WIDTH)
	{
		pos.y = 0;
		while (pos.y++ != HEIGHT)
		{
			new.re = 1.5 * (pos.x - WIDTH / 2) / (0.5 * WIDTH * pos.zoom);
			new.im = (pos.y - HEIGHT / 2) / (0.5 * HEIGHT * pos.zoom);
			i = 0;
			while (new.re * new.re + new.im * new.im <= 4 && i++ != MAX_ITER)
			{
				old.re = new.re;
				old.im = new.im;
				new.re = old.re * old.re - old.im * old.im + c.re;
				new.im = 2 * old.re * old.im + c.im;
			}
			if (i < MAX_ITER)
				my_mlx_pixel_put(&img, pos.x, pos.y, ft_color(i));
			else
				my_mlx_pixel_put(&img, pos.x, pos.y, 0x0);
		}
	}
}
