/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:40:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/09 13:37:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

# define WIDTH 1024
# define HEIGHT 820

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define EVENT_KEY_DOWN 2
# define KEY_W 13
# define EVENT_RED_CROSS 17
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

typedef struct s_cub3d {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_cub3d;

void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);
void	init_mlx(t_cub3d *data);
int		main(int ac, char **av);

#endif
