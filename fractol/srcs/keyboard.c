/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_keyboard(int keycode, t_f *p)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_DOWN
		|| keycode == ARROW_UP)
		ft_move_key(keycode, p);
	if (keycode == RESET)
	{
		mlx_clear_window(p->mlx, p->win);
		p->zoom = 0.8;
		p->move_x = 0.0;
		p->move_y = 0.0;
		if (!ft_strncmp(p->name, "Mandelbrot", 11))
			ft_mandelbrot_start(p);
		if (!ft_strncmp(p->name, "Julia", 5))
			ft_julia_start(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	if (keycode == PLUS_KEYPAD)
		ft_zoom_in(p);
	if (keycode == MINUS_KEYPAD)
		ft_zoom_out(p);
	return (0);
}

int	ft_move_key(int keycode, t_f *p)
{
	if (keycode == ARROW_LEFT)
		p->move_x -= 0.05 / p->zoom;
	if (keycode == ARROW_RIGHT)
		p->move_x += 0.05 / p->zoom;
	if (keycode == ARROW_DOWN)
		p->move_y += 0.05 / p->zoom;
	if (keycode == ARROW_UP)
		p->move_y -= 0.05 / p->zoom;
	mlx_clear_window(p->mlx, p->win);
	if (!ft_strncmp(p->name, "Mandelbrot", 11))
		ft_mandelbrot_start(p);
	if (!ft_strncmp(p->name, "Julia", 5))
		ft_julia_start(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}
