/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	(unsigned int *)*dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	y = 0;
	while (y != 5)
	{
		x = 0;
		while (x != 5)
		{
			my_mlx_pixel_put(&img, x, y, 0xffec8b);
			x++;
		}
		y++;
	}
	//int offset;
	// offset = (5 * img.line_length + 5 * (img.bits_per_pixel / 8));
	// x += offset;
	// y += offset;
	// mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 910, 540);
	mlx_loop(mlx_ptr);
}
