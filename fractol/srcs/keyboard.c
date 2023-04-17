/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
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
	if (keycode >= 18 && keycode <= 23)
		ft_change_color(keycode, f);
	return (0);
}

int	ft_move_key(int keycode, t_fractal *f)
{
	if (keycode == ARROW_LEFT)
		f->move_x -= f->zoom * 0.1;
	if (keycode == ARROW_RIGHT)
		f->move_x += f->zoom * 0.1;
	if (keycode == ARROW_DOWN)
		f->move_y += f->zoom * 0.1;
	if (keycode == ARROW_UP)
		f->move_y -= f->zoom * 0.1;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

void	ft_reset_fractal(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->mouse_lock = 0;
	f->max_iter = 50;
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
	if (keycode == ITER_MAX_DEC)
		f->max_iter -= 10;
	if (keycode == ITER_MAX_INC)
		f->max_iter += 10;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	ft_change_color(int keycode, t_fractal *f)
{
	if (keycode == 18)
		f->signal_color = 1;
	if (keycode == 19)
		f->signal_color = 2;
	if (keycode == 20)
		f->signal_color = 3;
	if (keycode == 21)
		f->signal_color = 4;
	if (keycode == 23)
		f->signal_color = 5;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
