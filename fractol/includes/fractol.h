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

# define WIDTH 1280
# define HEIGHT 720

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_f {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*name;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		max_iter;
	int		i;
	double	x;
	double	y;
	double	zoom;
	double	temp;
	double	move_x;
	double	move_y;
	double	re;
	double	im;
	double	c_re;
	double	c_im;
}				t_f;

/* main.c */
int			main(int argc, char **argv);
void		init_fractol(t_f *p);
void		check_arg(int argc, char **argv);
void		hooks(t_f *p);

/* mandelbrot.c */
void		ft_mandelbrot_start(t_f *p);
void		ft_mandelbrot(t_f *p);

/* julia.c */
void		ft_julia_start(t_f *p);
void		which_julia(t_f *p);
void		ft_julia(t_f *p);

/* keyboard.c */
int			ft_keyboard(int keycode, t_f *p);

/* mouse.c */
int			ft_mouse(int mousecode, t_f *p);

/* utils.c */
int			ft_exit(void);
void		my_mlx_pixel_put(t_f *p, int x, int y, int color);
int			ft_color(int count);

#endif
