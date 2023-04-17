/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:06:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/17 09:06:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* 
	modulo the count by the number of colors
	to determine which ranks of the tab/colors for the current pixel
*/
int	color_palette_one(t_fractal *f)
{
	int	tab[18];

	tab[0] = 0x220724;
	tab[1] = 0x360f38;
	tab[2] = 0x09012f;
	tab[3] = 0x14055c;
	tab[4] = 0x040e8c;
	tab[5] = 0x15379e;
	tab[6] = 0x2660bf;
	tab[7] = 0x5d99e3;
	tab[8] = 0x94bbe3;
	tab[9] = 0xd3ecf8;
	tab[10] = 0xf1e9bf;
	tab[11] = 0xffe7ba;
	tab[12] = 0xf8c95f;
	tab[13] = 0xfab62d;
	tab[14] = 0xffaa00;
	tab[15] = 0xcc8000;
	tab[16] = 0x995700;
	tab[17] = 0x6a3403;
	return (tab[f->nb_iter % 18]);
}

int	color_palette_two(t_fractal *f)
{
	int	tab[20];

	tab[0] = 0x6400;
	tab[1] = 0x556b2f;
	tab[2] = 0x8fbc8f;
	tab[3] = 0x3cb371;
	tab[4] = 0x2e8b57;
	tab[5] = 0x98fb98;
	tab[6] = 0x20b2aa;
	tab[7] = 0x98fb98;
	tab[8] = 0xff7f;
	tab[9] = 0x7cfc00;
	tab[10] = 0xadff2f;
	tab[11] = 0x32cd32;
	tab[12] = 0x9acd32;
	tab[13] = 0x228b22;
	tab[14] = 0x6b8e23;
	tab[15] = 0xbdb76b;
	tab[16] = 0xeee8aa;
	tab[17] = 0xfafad2;
	tab[18] = 0xffffe0;
	tab[19] = 0xffd700;
	return (tab[f->nb_iter % 20]);
}

int	color_palette_three(t_fractal *f)
{
	int	tab[14];

	tab[0] = 0xc0392b;
	tab[1] = 0xe74c3c;
	tab[2] = 0x9b59b6;
	tab[3] = 0x8e44ad;
	tab[4] = 0x2980b9;
	tab[5] = 0x3498db;
	tab[6] = 0x1abc9c;
	tab[7] = 0x16a085;
	tab[8] = 0x27ae60;
	tab[9] = 0x2ecc71;
	tab[10] = 0xf1c40f;
	tab[11] = 0xf39c12;
	tab[12] = 0xe67e22;
	tab[13] = 0xd35400;
	return (tab[f->nb_iter % 14]);
}

int	color_palette_four(t_fractal *f)
{
	int	tab[20];

	tab[0] = 0xfffafa;
	tab[1] = 0xffdab9;
	tab[2] = 0x778899;
	tab[3] = 0x4169e1;
	tab[4] = 0xffff;
	tab[5] = 0xff00;
	tab[6] = 0xeedd82;
	tab[7] = 0xffa07a;
	tab[8] = 0xee82ee;
	tab[9] = 0x8b8378;
	tab[10] = 0xe0eee0;
	tab[11] = 0x8b;
	tab[12] = 0xbcd2ee;
	tab[13] = 0x8b8b;
	tab[14] = 0xee00;
	tab[15] = 0x8b8b7a;
	tab[16] = 0xee7942;
	tab[17] = 0x8b2323;
	tab[18] = 0xee4000;
	tab[19] = 0x8b475d;
	return (tab[f->nb_iter % 20]);
}

int	color_palette_five(t_fractal *f)
{
	int	tab[12];

	tab[0] = 0xff0000;
	tab[1] = 0xE34234;
	tab[2] = 0xFFA500;
	tab[3] = 0xCC7722;
	tab[4] = 0xFFFF00;
	tab[5] = 0x7FFF00;
	tab[6] = 0x00FF00;
	tab[7] = 0x30D5C8;
	tab[8] = 0x0000FF;
	tab[9] = 0x4B0082;
	tab[10] = 0x8F00FF;
	tab[11] = 0x9e0e40;
	return (tab[f->nb_iter % 12]);
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
