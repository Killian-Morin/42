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

void	ft_julia(t_f *p)
{
	double	temp;
	int		i;

	p->c_re = -0.7;
	p->c_im = 0.27015;
	p->x = 0;
	p->move_x = 0;
	p->move_y = 0;
	while (p->x++ != WIDTH)
	{
		p->y = 0;
		while (p->y++ != HEIGHT)
		{
			p->re = 1.5 * (p->x - WIDTH / 2) / (0.5 * p->zoom * WIDTH) + p->move_x;
			p->im = (p->y - HEIGHT / 2) / (0.5 * p->zoom * HEIGHT) + p->move_y;
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
