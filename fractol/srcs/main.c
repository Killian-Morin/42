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

void	hooks(t_f *p)
{
	mlx_hook(p->win, EVENT_KEY_DOWN, 0, ft_keyboard, p);
	mlx_hook(p->win, EVENT_MOUSE_DOWN, 0, ft_mouse, p);
	// mlx_hook(p->win, EVENT_MOUSE_MOVE, 0, ft_change_julia, p);
	mlx_hook(p->win, EVENT_RED_CROSS, 0, ft_exit, EXIT_SUCCESS);
}

void	init_fractol(t_f *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, p->name);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
			&p->line_lenght, &p->endian);
	p->zoom = 0.8;
	p->move_x = 0.0;
	p->move_y = 0.0;
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
	t_f	*p;

	check_arg(argc, argv);
	p = malloc(sizeof(t_f));
	if (!p)
		return (EXIT_FAILURE);
	p->name = argv[1];
	if (argv[2])
		p->max_iter = ft_atoi(argv[2]);
	else
		p->max_iter = 50;
	init_fractol(p);
	if (!ft_strncmp(p->name, "Mandelbrot", 11))
	{
		ft_mandelbrot_start(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	if (!ft_strncmp(p->name, "Julia", 5))
	{
		ft_julia_start(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	hooks(p);
	mlx_loop(p->mlx);
	return (0);
}
