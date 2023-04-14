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

/*
    function that simply exit while returning a int
    used in mlx_hook for the function that is called when closing the window
    use this one instead of exit() since the function used in mlx_hook has to
    return an int
*/
int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

/*
    to use instead of mlx_pixel_put | mimic its behaviour
    calculate the offset of the pixels to align them correctly
*/
void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_lenght + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* 
	16 colors available, so modulo the count by the number of colors
	to determine which colors for the current pixel
*/
int	ft_color(int count)
{
	int	tab[16];

	tab[0] = 0x0;
	tab[1] = 0x19071a;
	tab[2] = 0x09012f;
	tab[3] = 0x040449;
	tab[4] = 0x000764;
	tab[5] = 0x0c2c8a;
	tab[6] = 0x1852b1;
	tab[7] = 0x397dd1;
	tab[8] = 0x86b5e5;
	tab[9] = 0xd3ecf8;
	tab[10] = 0xf1e9bf;
	tab[11] = 0xf8c95f;
	tab[12] = 0xffaa00;
	tab[13] = 0xcc8000;
	tab[14] = 0x995700;
	tab[15] = 0x6a3403;
	return (tab[count % 16]);
}

/*
	color set:
	0x559597, 0xd0e1b8, 0x9c9b86, 0x87c9ac, 0x44444c
	0xFE0000, 0xFF7900, 0xFFFF0B, 0x22DB13, 0x2430FF, 0x660092, 0xC800F9

	functions for colors with bases
	base red:
	void	color_red(int count)
	{
		int	r;
		int	g;
		int	b;

		r = 255 % count;
		g = 0 % count;
		b = 0 % count;
		return ()
	}
	base green:
	void	color_green(int count)
	{
		int	r;
		int	g;
		int	b;

		r = 0 % count;
		g = 255 % count;
		b = 0 % count;
		return ()
	}
	base blue:
	void	color_blue(int count)
	{
		int	r;
		int	g;
		int	b;

		r = 0 % count;
		g = 0 % count;
		b = 255 % count;
		return ()
	}
*/
