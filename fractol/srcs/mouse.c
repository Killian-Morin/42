/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse(int mousecode, int x, int y, t_fractal *f)
{
	if (mousecode == ZOOM_MOUSE)
		ft_zoom(x, y, f, 0.9);
	if (mousecode == DEZOOM_MOUSE)
		ft_zoom(x, y, f, 1.1);
	return (0);
}

void	ft_zoom(int x, int y, t_fractal *f, double zoom)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = 4.0 * f->zoom;
	h = 4.0 * f->zoom;
	nw = 4.0 * (f->zoom * zoom);
	nh = 4.0 * (f->zoom * zoom);
	f->zoom *= zoom;
	f->move_x -= ((double)x / WIDTH) * (nw - w);
	f->move_y -= ((double)y / HEIGHT) * (nh - h);
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		mandelbrot_iter(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		julia_iter(f);
	if (!ft_strncmp(f->name, "Burningship", 12))
		burning_ship_iter(f);
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
