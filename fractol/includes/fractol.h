/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:21:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/13 11:24:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 820
# define HEIGHT 656

# define EVENT_KEY_DOWN 2
# define EVENT_MOUSE_DOWN 4
# define EVENT_MOUSE_MOVE 6
# define EVENT_RED_CROSS 17

# define ZOOM_MOUSE 4
# define DEZOOM_MOUSE 5

# define ITER_MAX_DEC 0
# define ITER_MAX_INC 2
# define LOCK_MOUSE 3
# define RESET 15
# define DIGIT_1 18
# define DIGIT_2 19
# define DIGIT_3 20
# define DIGIT_4 21
# define DIGIT_5 23
# define ESC 53
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

typedef struct s_fractal {
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
	int		mouse_lock;
	int		color_palette;
	double	zoom;
	double	temp;
	double	pxl_x;
	double	pxl_y;
	double	move_x;
	double	move_y;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re;
	double	im;
	double	c_re;
	double	c_im;
}				t_fractal;

/*
	main.c
*/
int			main(int argc, char **argv);
void		init_mlx(t_fractal *f);
void		init_fractol(t_fractal *f);
void		check_arg(int argc, char **argv);
void		hooks(t_fractal *f);

/*
	mandelbrot.c
*/
void		mandelbrot_iter(t_fractal *f);
void		mandelbrot(t_fractal *f);
void		mandelbrot_init(t_fractal *f);

/*
	julia.c
*/
void		julia_iter(t_fractal *f);
void		julia(t_fractal *f);
void		julia_init(t_fractal *f);

/*
	burningship.c
*/
void		burning_ship_iter(t_fractal *f);
void		burning_ship(t_fractal *f);
void		burning_ship_init(t_fractal *f);

/*
	keyboard.c
*/
int			ft_keyboard(int keycode, t_fractal *f);
int			ft_move_key(int keycode, t_fractal *f);
void		ft_reset_fractal(t_fractal *f);
void		ft_change_iter_max(int keycode, t_fractal *f);
void		ft_change_color(int keycode, t_fractal *f);

/*
	mouse.c
*/
int			ft_mouse(int mousecode, int x, int y, t_fractal *f);
int			ft_change_julia(int x, int y, t_fractal *f);
void		ft_zoom(int x, int y, t_fractal *f, double zoom);

/*
	utils.c
*/
int			ft_exit(void);
void		my_mlx_pixel_put(t_fractal *f, int x, int y, int color);
int			ft_determine_color(t_fractal *f);

/*
	color.c
*/
int			color_palette_one(t_fractal *f);
int			color_palette_two(t_fractal *f);
int			color_palette_three(t_fractal *f);
int			color_palette_four(t_fractal *f);
int			color_palette_five(t_fractal *f);

#endif
