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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	(unsigned int *)*dst = color;
}

void	ft_start_fractol(char *fractal)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, fractal);
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	y = 0;
	while (y != 5)
	{
		x = 0;
		while (x != 5)
		{
			my_mlx_pixel_put(&img, x, y, 0xffd700);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 910, 540);
	mlx_key_hook(win_ptr, (int mlx_destroy_image(void *mlx_ptr, void *img.img)), img.img);
	mlx_loop(mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Needs at least one parameter.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		return (-1);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0
		|| ft_strncmp(argv[1], "Julia", 6) == 0)
		ft_start_fractol(argv[1]);
	else
	{
		ft_putstr_fd("Wrong parameters.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		return (-1);
	}
	return (0);
}
