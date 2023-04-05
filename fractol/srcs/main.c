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

void	hooks(t_fractal *f)
{
	mlx_hook(f->win, EVENT_KEY_DOWN, 0, ft_keyboard, f);
	mlx_hook(f->win, EVENT_MOUSE_DOWN, 0, ft_mouse, f);
	mlx_hook(f->win, EVENT_MOUSE_MOVE, 0, ft_change_julia, f);
	mlx_hook(f->win, EVENT_RED_CROSS, 0, ft_exit, EXIT_SUCCESS);
}

void	init_fractol(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_lenght, &f->endian);
	f->zoom = 0.8;
	f->move_x = 0.0;
	f->move_y = 0.0;
	mlx_mouse_move(f->win, WIDTH / 2, HEIGHT / 2);
	if (!ft_strncmp(f->name, "Mandelbrot", 11))
		ft_mandelbrot_start(f);
	if (!ft_strncmp(f->name, "Julia", 5))
	{
		which_julia(f);
		ft_julia_start(f);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	check_arg(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Needs at least one parameter.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) != 0
		&& ft_strncmp(argv[1], "Julia", 5) != 0)
	{
		ft_putstr_fd("Sorry invalid parameters.\n", 1);
		ft_putstr_fd("List of avalaible parameters:\nMandelbrot\nJulia\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	*f;

	check_arg(argc, argv);
	f = malloc(sizeof(t_fractal));
	if (!f)
		return (EXIT_FAILURE);
	f->name = argv[1];
	if (argv[2])
		f->max_iter = ft_atoi(argv[2]);
	else
		f->max_iter = 50;
	init_fractol(f);
	hooks(f);
	mlx_loop(f->mlx);
	return (0);
}
