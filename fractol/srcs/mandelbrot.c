/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot(t_data *data, t_vars *vars)
{
	int	*x;
	int	*y;
	int	iteration;
	int	max_iteration;

	x = 0;
	y = 0;
	iteration = 0;
	max_iteration = 100;
	while ((((x * x) + (y * y)) <= (2 * 2)) && iteration < max_iteration)
	{
		x[iteration] = (x * x) - (y * y) + x[0];
		y = 2 * xy * y + y[0];
		x = x[iteration];
		iteration++;
	}
	if (iteration == max_iteration)
		color = black;
	my_mlx_pixel_put(&img, x[0], y[0], color);
	if (iteration != max_iteration)
		color = iteration;
	my_mlx_pixel_put(&img, x[0], y[0], color);
}
