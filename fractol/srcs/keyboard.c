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

int	ft_keyboard(int keycode, t_fractal *f)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_DOWN
		|| keycode == ARROW_UP)
		ft_move_key(keycode, f);
	if (keycode == RESET)
		ft_reset_fractal(f);
	if (keycode == PLUS_KEYPAD)
		ft_zoom_in(f);
	if (keycode == MINUS_KEYPAD)
		ft_zoom_out(f);
	return (0);
}

void	ft_reset_fractal(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->zoom = 0.8;
	f->move_x = 0.0;
	f->move_y = 0.0;
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		ft_mandelbrot_start(f);
	if (!ft_strncmp(f->name, "Julia", 5))
	{
		f->c_re = 0.0;
		f->c_im = 0.0;
		ft_julia_start(f);
	}
	mlx_mouse_move(f->win, WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	ft_move_key(int keycode, t_fractal *f)
{
	if (keycode == ARROW_LEFT)
		f->move_x -= 0.1 / f->zoom;
	if (keycode == ARROW_RIGHT)
		f->move_x += 0.1 / f->zoom;
	if (keycode == ARROW_DOWN)
		f->move_y += 0.1 / f->zoom;
	if (keycode == ARROW_UP)
		f->move_y -= 0.1 / f->zoom;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		ft_mandelbrot_start(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		ft_julia_start(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
