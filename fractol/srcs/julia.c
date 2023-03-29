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

void	ft_julia_start(t_f *p)
{
	p->y = 0;
	p->move_x = 0;
	p->move_y = 0;
	while (p->y != HEIGHT)
	{
		p->x = 0;
		while (p->x != WIDTH)
		{
			p->i = 0;
			p->re = 0;
			p->im = 0;
			if (p->i < p->max_iter)
				ft_julia(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	which_julia(t_f *p)
{
	if (ft_strncmp(p->name, "Julia1", 7) == 0)
	{
		p->c_re = -0.2321;
		p->c_im = -0.835;
	}
	else if (ft_strncmp(p->name, "Julia2", 7) == 0)
	{
		p->c_re = -0.3842;
		p->c_im = -0.70176;
	}
	else
	{
		p->c_re = 0.01;
		p->c_im = 0.285;
	}
}

void	ft_julia(t_f *p)
{
	which_julia(p);
	p->re = 1.5 * (p->x - WIDTH / 2) / (0.5 * p->zoom * WIDTH) + p->move_x;
	p->im = (p->y - HEIGHT / 2) / (0.5 * p->zoom * HEIGHT) + p->move_y;
	while (p->re * p->re + p->im * p->im <= 4 && p->i != p->max_iter)
	{
		p->temp = p->re * p->re - p->im * p->im + p->c_re;
		p->im = 2 * p->re * p->im + p->c_im;
		p->re = p->temp;
		p->i++;
	}
	if (p->i < p->max_iter)
		my_mlx_pixel_put(p, p->x, p->y, ft_color(p->i));
	else
		my_mlx_pixel_put(p, p->x, p->y, ft_color(0));
}
