/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_start_fractol(char *fractal)
{
	t_vars	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, fractal);
	ptr.img.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.img.addr = mlx_get_data_addr(ptr.img.img, &ptr.img.bits_per_pixel, &ptr.img.line_length,
			&ptr.img.endian);
	ptr.pos.zoom = 1.0;
	if (ft_strncmp(fractal, "Mandelbrot", 11) == 0)
		ft_mandelbrot(ptr);
	else if (ft_strncmp(fractal, "Julia", 6) == 0)
		ft_julia(ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img.img, 0, 0);
	mlx_key_hook(ptr.win, ft_keyboard, &ptr);
	mlx_mouse_hook(ptr.win, ft_mouse, &ptr);
	mlx_hook(ptr.win, 17, 0, ft_exit, EXIT_SUCCESS);
	mlx_loop(ptr.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Needs at least one parameter.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0
		|| ft_strncmp(argv[1], "Julia", 6) == 0)
		ft_start_fractol(argv[1]);
	else
	{
		ft_putstr_fd("Sorry invalid parameters.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
