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
		exit(EXIT_SUCCESS);
	if (keycode == LOCK_MOUSE && f->mouse_lock == 1)
		f->mouse_lock = 0;
	else if (keycode == LOCK_MOUSE && f->mouse_lock == 0)
		f->mouse_lock = 1;
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_DOWN
		|| keycode == ARROW_UP)
		ft_move_key(keycode, f);
	if (keycode == RESET)
		ft_reset_fractal(f);
	if (keycode == 0 || keycode == 2)
		ft_change_iter_max(keycode, f);
	// if (keycode == PLUS_KEYPAD)
	// 	ft_zoom_in(f);
	// if (keycode == MINUS_KEYPAD)
	// 	ft_zoom_out(f);
	return (0);
}

void	ft_reset_fractal(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->zoom = 0.8;
	f->move_x = 0.0;
	f->move_y = 0.0;
	f->mouse_lock = 1;
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
	{
		mandelbrot_init(f);
		mandelbrot_iter(f);
	}
	if (!ft_strncmp(f->name, "Julia", 5))
	{
		julia_init(f);
		julia_iter(f);
	}
	mlx_mouse_move(f->win, WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	ft_change_iter_max(int keycode, t_fractal *f)
{
	if (keycode == 0)
		f->max_iter -= 10;
	if (keycode == 2)
		f->max_iter += 10;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
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
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
