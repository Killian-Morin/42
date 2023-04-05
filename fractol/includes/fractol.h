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

# define WIDTH 1024
# define HEIGHT 576

# define EVENT_KEY_DOWN 2
# define EVENT_MOUSE_DOWN 4
# define EVENT_MOUSE_MOVE 6
# define EVENT_RED_CROSS 17

# define ZOOM_MOUSE 4
# define DEZOOM_MOUSE 5
# define RESET 15
# define ESC 53
# define PLUS_KEYPAD 69
# define MINUS_KEYPAD 78
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

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
	int		nb_iter;
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

/*
main.c
*/
int			main(int argc, char **argv);
void		init_fractol(t_f *p);
void		check_arg(int argc, char **argv);
void		hooks(t_f *p);

/*
mandelbrot.c
*/
void		ft_mandelbrot_start(t_f *p);
void		ft_mandelbrot(t_f *p);

/*
julia.c
*/
void		ft_julia_start(t_f *p);
void		which_julia(t_f *p);
void		ft_julia(t_f *p);

/*
keyboard.c
*/
int			ft_keyboard(int keycode, t_f *p);
int			ft_move_key(int keycode, t_f *p);
void		ft_reset_fractal(t_f *p);

/*
mouse.c
*/
int			ft_mouse(int mousecode, int x, int y, t_f *p);
int			ft_change_julia(int x, int y, t_f *p);
void		ft_zoom_in(t_f *p);
void		ft_zoom_out(t_f *p);

/*
utils.c
*/
int			ft_exit(void);
void		my_mlx_pixel_put(t_f *p, int x, int y, int color);
int			ft_color(int count);

#endif
