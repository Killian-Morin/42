/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse(int mousecode, int x, int y, t_fractal *f)
{
	if (mousecode == ZOOM_MOUSE)
		ft_zoom_in(x, y, f);
	if (mousecode == DEZOOM_MOUSE)
		ft_zoom_out(x, y, f);
	return (0);
}

void	ft_zoom_in(int x, int y, t_fractal *f)
{
	double	nw;
	double	nh;

	nw = (f->x_max - f->x_min) * (f->zoom * 1.1);
	nh = (f->y_max - f->y_min) * (f->zoom * 1.1);
	f->move_x -= ((double)x / WIDTH) * (nw);
	f->move_y -= ((double)y / HEIGHT) * (nh);
	f->zoom *= 1.1;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	ft_zoom_out(int x, int y, t_fractal *f)
{
	double	nw;
	double	nh;

	nw = (f->x_max - f->x_min) * (f->zoom * 0.9);
	nh = (f->y_max - f->y_min) * (f->zoom * 0.9);
	f->move_x -= ((double)x / WIDTH) * (nw);
	f->move_y -= ((double)y / HEIGHT) * (nh);
	f->zoom *= 0.9;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	ft_change_julia(int x, int y, t_fractal *f)
{
	if (!ft_strncmp(f->name, "Julia", 5) && f->mouse_lock == 1)
	{
		f->c_re = 1.5 * (x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->move_x;
		f->c_im = (y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->move_y;
		mlx_clear_window(f->mlx, f->win);
		julia_iter(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	return (0);
}
