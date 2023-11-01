/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:40:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/31 16:45:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

//from parsing
# include <string.h>
# include <errno.h>
# include <stdbool.h>

/* WINDOW SIZE */
# define WIDTH 1024
# define HEIGHT 820

/* KEYBOARD EVENT */
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PRESS 2
# define KEY_H 4
# define MOUSE_MOVE 6
# define KEY_W 13
# define KEY_R 15
# define RED_CROSS 17
# define KEY_P 35
# define KEY_M 46
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

/* must be power of two */
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

/* COLOR */
# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"

# ifndef BONUS
#  define BONUS 0
# endif

/* for the minimap */
# define SQUARE_SIZE 64
# define SQUARE_SIZE_2 11
# define PI 3.14159265358979323846

/*
	variables used by/for the mlx
*/
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_mlx;

/*
	all variables used for the ray casting of the floor/ceiling (lodev way)
cam_z_pos -> vertical position of the camera
row_distance -> horizontal distance from camera to the floor/ceiling
	for the current row
floor_step_x/y -> calculate the real world step vector we have to add
	for each x (parallel to camera plane)
floor_x/y -> real world coordinates of the leftmost column
*/
typedef struct s_floor {
	float	ray_dir_x0;
	float	ray_dir_y0;
	float	ray_dir_x1;
	float	ray_dir_y1;
	float	cam_z_pos;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
}	t_floor;

/*
	all variables used for the ray casting of the walls
*/
typedef struct s_wall {
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_dir;
}	t_wall;

/*
	all variables concerning the player
*/
typedef struct s_player {
	double	angle;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	move_speed;
	double	rot_speed;
	int		mouse_lock;
}	t_player;

/*
	all info taken from the file
*/
typedef struct s_file {
	int		map_max_x;
	int		map_max_y;
	int		floor_color;
	int		ceiling_color;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	char	**map;
}	t_file;

typedef struct s_texture {
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_cond
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			error;
}	t_cond;

typedef struct s_draw_line
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		delta_x;
	int		delta_y;
	int		increment_x;
	int		increment_y;
}	t_draw_line;

typedef struct s_minimap
{
	double		x;
	double		y;
	double		x_pixel;
	double		y_pixel;
	double		fov;
	double		*dist;
	double		*ang;
}	t_minimap;

/*
	main structure
*/
typedef struct s_cub3d {
	t_mlx		*mlx_text;
	t_mlx		*mlx;
	t_texture	*t;
	t_floor		f_c;
	t_wall		wall;
	t_file		file;
	t_player	p;
	t_cond		cond;
	t_minimap	*minimap;
}	t_cub3d;

enum e_id
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

/*
	*
	*
	BONUS
	*
	*
*/

/* bonus/collision.c */
bool		check_collision(t_cub3d *data, double new_pos_x, double new_pos_y);

/* bonus/minimap_grid.c */
void		draw_horizontal_grid(t_cub3d *data, int x_, int y_);
void		draw_vertical_grid(t_cub3d *data, int x_, int y_);
void		draw_grid(t_cub3d *data);

/* bonus/minimap_player.c */
void		set_player_attributes(t_cub3d *data, t_minimap *minimap);
void		draw_player(t_cub3d *data, t_minimap *minimap);

/* bonus/minimap_rays.c 
	not in Makefile since could not make it work
*/
void		bresenhams_line_algorithm(t_cub3d *data, t_draw_line *l, int color);
void		draw_mini_line(t_cub3d *data, double line_length, double angle);
void		draw_rays_minimap(t_cub3d *data);

/* bonus/minimap.c */
void		draw(t_cub3d *data, int color, int x, int y);
void		draw_map(t_cub3d *data);
void		minimap(t_cub3d *data);

/* bonus/mouse.c */
int			ft_mouse(int x, int y, t_cub3d *data);

/*
 	*
 	*
 	DEPLACEMENT
 	*
	*
*/

/* deplacement/mouvement.c */
void		move_up(t_cub3d *data);
void		move_down(t_cub3d *data);
void		move_right(t_cub3d *data);
void		move_left(t_cub3d *data);
void		move(t_cub3d *data, int keycode);

/* deplacement/rotation.c */
void		rotate_left(t_cub3d *data);
void		rotate_right(t_cub3d *data);
void		rotate(t_cub3d *data, int keycode);

/*
	*
	*
	PARSING
	*
	*
*/

/* parsing/color.c */
int			get_len_tab(char **tab);
void		check_virgule(char *s, t_list *node, t_cub3d *data);
void		check_res_split(char **res, t_list *node, t_cub3d *data);
int			get_int(char *s, t_list *node, t_cub3d *data);
bool		get_color(char *s, enum e_id key, t_list *node, t_cub3d *data);

/* parsing/element.c */
void		check_which_missing(t_cub3d *data, t_list *node);
void		check_multiple_declaration(enum e_id key, t_list *node, t_cub3d *d);
bool		check_get_elements(char *s, t_list *node, t_cub3d *data);
t_list		*check_elements(t_list **head_element, t_cub3d *data);

/* parsing/empty_line.c */
bool		is_whitespace(char c);
bool		is_space(char c);
bool		is_empty_line(char *s);
char		*remove_empty_lines(int fd);

/* parsing/error.c */
void		error_msg_exit(char *s1, char *s2);
void		free_texture_file(t_file *file);
void		parser_error_exit(char *s1, char *s2, t_cub3d *data);
void		free_tab_size(char **array, int size_y);

/* parsing/extract.c */
t_list		*create_head(char *line);
void		join_new_node(t_list **node, t_list **head, char *line);
void		create_linked_list(t_list *node, t_list **head, int fd, char *line);
int			open_file(char *s);
t_list		*copy_content_to_list(char *s);

/* parsing/map_check_utils.c */
bool		is_valid_char(char c);
void		get_map_size_list(t_list *map_node, t_file *file);
char		*cpy_str(char *str, int size);
void		copy_map(t_list *map_node, t_file *file);
void		change_map(t_file *file);

/* parsing/map_check_walls.c */
void		walls_checker_top(t_file *f);
void		walls_checker_left(t_file *f);
void		walls_checker_bottom(t_file *f);
void		walls_checker_right(t_file *f);
void		walls_checker(t_file *file);

/* parsing/map_check_walls2.c */
void		exit_error_map(int x, int y, t_file *f);
void		check_angle(char **map, int x, int y, t_file *f);
int			helper(int x, int y, char **map, t_file *f);
void		walls(t_file *f, char **map);

/* parsing/map_check.c */
void		cara_checker(t_file *file);
void		nb_player_checker(t_file *file);
void		remove_empty_lines_after_map(t_list **head);
void		check_empty_line_in_map(t_list *map, t_cub3d *data);
void		check_map(t_list *head_map, t_cub3d *data);

/* parsing/parser.c */
void		extension_check(char *s);
void		get_player_direction(char **map, t_player *p);
void		parser(t_cub3d *data, char *av, t_list *head);

/* parsing/player.c */
void		init_north_direction(t_player *p);
void		init_south_direction(t_player *p);
void		init_west_direction(t_player *p);
void		init_east_direction(t_player *p);
int			is_on_player(t_player *p, char c);

/* parsing/texture.c */
void		set_value_texture(char *file_name, enum e_id key, t_cub3d *data);
bool		get_texture_file(char *s, enum e_id key, t_list *node, t_cub3d *d);

/* parsing/utils.c */
void		set_cond_flag(enum e_id key, t_cond *cond);
int			check_cond_flag(t_cond *cond);
int			find_start(char *s);
int			find_len(char *s, int i);

/*
	*
	*
	RAYCASTING
	*
	*
*/

/* floor_ceiling_casting.c */
void		floor_ceiling_casting(t_cub3d *data);

/* init_textures.c */
void		new_window(t_cub3d *data);
void		get_textures_address(t_cub3d *data, int i, t_mlx *mlx_text);
void		init_textures(t_cub3d *data);

/* texture_mapping.c */
int			get_tex_num(t_cub3d *data, double *wall_x);
int			calculate_tex_x(t_cub3d *data, double wall_x);
void		get_texture_color(t_cub3d *data, int tex_num, int tex_x, int x);
void		texture_mapping(t_cub3d *data, int x);

/* wall_casting.c */
void		wall_casting_init(t_cub3d *data, int x);
void		wall_casting_side_dist(t_cub3d *data);
void		wall_casting_dda(t_cub3d *data);
void		wall_casting_wall_height(t_cub3d *data);
void		wall_casting(t_cub3d *data);

/*
	*
	*
	OTHER
	*
	*
*/

/* keyboard.c */
int			ft_exit(t_cub3d *data);
int			keyboard_manager(int keycode, t_cub3d *data);

/* main.c */
void		start(t_cub3d *data);
void		init_var(t_cub3d *data);
int			main(int ac, char **av);

/* mlx.c */
void		my_mlx_pixel_put(t_cub3d *d, int x, int y, int color);
void		hooks(t_cub3d *data);
void		init_mlx(t_cub3d *data);

/* utils.c */
void		free_tab(char **tmp);
void		exit_routine(t_cub3d *data, int msg_nb, int exit_code);
void		error_exit(char *s, int exit_code);
void		explanation_text(void);

#endif
