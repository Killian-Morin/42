/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:21:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/13 11:24:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 920
# define HEIGHT 540
# define MAX_ITER 300

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_complex {
	double	re;
	double	im;
}				t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/* main.c */
int			main(int argc, char **argv);
void		ft_start_fractol(char *fractal);

/* mandelbrot.c */
void		ft_mandelbrot(t_data img);

/* julia.c */
void		ft_julia(t_data img);

/* keyboard.c */
int			ft_keyboard(int keycode, t_vars *vars);

/* mouse.c */
int			ft_mouse(int mousecode, t_vars *vars);

/* utils.c */
int			ft_exit(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_absolute(int n);
int			ft_color(int count);

#endif
