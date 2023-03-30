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
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_move_key(keycode, p);
	if (keycode == 15)
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
	return (0);
}

int	ft_move_key(int keycode, t_f *p)
{
	if (keycode == 123)
		p->move_x -= 0.05;
	else if (keycode == 124)
		p->move_x += 0.05;
	else if (keycode == 125)
		p->move_y += 0.05;
	else if (keycode == 126)
		p->move_y -= 0.05;
	mlx_clear_window(p->mlx, p->win);
	if (!ft_strncmp(p->name, "Mandelbrot", 11))
		ft_mandelbrot_start(p);
	if (!ft_strncmp(p->name, "Julia", 5))
		ft_julia_start(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

/*
int ft_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 69)
		ft_zoom();
	if (keycode == 78)
		ft_zoom();
    return (0);
}*/
