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
	if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		ft_move_key(keycode, f);
	if (keycode == RESET)
		ft_reset_fractal(f);
	if (keycode == ITER_MAX_DEC || keycode == ITER_MAX_INC)
		ft_change_iter_max(keycode, f);
	if (keycode >= DIGIT_1 && keycode <= DIGIT_5)
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
	if (!ft_strncmp(f->name, "Burningship", 12))
		burning_ship_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

void	ft_reset_fractal(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->mouse_lock = 0;
	f->max_iter = 50;
	init_fractol(f);
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
	if (!ft_strncmp(f->name, "Burningship", 12))
		burning_ship_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	ft_change_color(int keycode, t_fractal *f)
{
	if (keycode == DIGIT_1)
		f->color_palette = 1;
	if (keycode == DIGIT_2)
		f->color_palette = 2;
	if (keycode == DIGIT_3)
		f->color_palette = 3;
	if (keycode == DIGIT_4)
		f->color_palette = 4;
	if (keycode == DIGIT_5)
		f->color_palette = 5;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	if (!ft_strncmp(f->name, "Burningship", 12))
		burning_ship_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
