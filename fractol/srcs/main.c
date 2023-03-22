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

void	ft_draw(t_data img)
{
	int	x;
	int	y;

	y = 0;
	while (y++ != 10)
	{
		x = 0;
		while (x++ != 10)
			my_mlx_pixel_put(&img, x, y, 0xffd700);
	}
	y = 0;
	while (y++ != 10)
	{
		x = 50;
		while (x++ != 60)
			my_mlx_pixel_put(&img, x, y, 0xffd700);
	}
	y = 50;
	while (y++ != 54)
	{
		x = 0;
		while (x++ != 60)
			my_mlx_pixel_put(&img, x, y, 0xffd700);
	}
}

void	ft_start_fractol(char *fractal)
{
	t_data	img;
	t_vars	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, fractal);
	img.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// ft_draw(img);
	ft_mandelbrot(img);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 910, 540);
	mlx_key_hook(ptr.win, ft_keyboard, &ptr);
	mlx_hook(ptr.win, 17, 0, ft_exit, EXIT_SUCCESS);
	// mlx_mouse_hook(ptr.win, ft_mouse, &ptr);
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
		ft_putstr_fd("Wrong parameters.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
