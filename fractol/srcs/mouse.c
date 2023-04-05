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
	(void)x;
	(void)y;
	if (mousecode == ZOOM_MOUSE)
		ft_zoom_in(f);
	if (mousecode == DEZOOM_MOUSE)
		ft_zoom_out(f);
	return (0);
}

void	ft_zoom_in(t_fractal *f)
{
	f->zoom *= 1.1;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		ft_mandelbrot_start(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		ft_julia_start(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	ft_zoom_out(t_fractal *f)
{
	f->zoom /= 1.1;
	mlx_clear_window(f->mlx, f->win);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		ft_mandelbrot_start(f);
	if (!ft_strncmp(f->name, "Julia", 5))
		ft_julia_start(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	ft_change_julia(int x, int y, t_fractal *f)
{
	if (!ft_strncmp(f->name, "Julia", 5))
	{
		f->c_re = (double)x;
		f->c_im = (double)y;
		mlx_clear_window(f->mlx, f->win);
		ft_julia_start(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	return (0);
}
