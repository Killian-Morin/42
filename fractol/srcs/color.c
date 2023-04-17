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
	return (tab[f->nb_iter % 16]);
}

int	color_palette_two(t_fractal *f)
{
	int	tab[16];

	tab[0] = 0x0;
	tab[1] = 0x191a07;
	tab[2] = 0x092f01;
	tab[3] = 0x044904;
	tab[4] = 0x006407;
	tab[5] = 0x0c8a2c;
	tab[6] = 0x18b153;
	tab[7] = 0x39d17d;
	tab[8] = 0x86e5b6;
	tab[9] = 0xd3f8ec;
	tab[10] = 0xf1e9bf;
	tab[11] = 0xf8c95f;
	tab[12] = 0xffaa00;
	tab[13] = 0xcc8000;
	tab[14] = 0x995700;
	tab[15] = 0x6a3403;
	return (tab[f->nb_iter % 16]);
}

int	color_palette_three(t_fractal *f)
{
	int	tab[16];

	tab[0] = 0x0;
	tab[1] = 0x1a0719;
	tab[2] = 0x2f0109;
	tab[3] = 0x490404;
	tab[4] = 0x640700;
	tab[5] = 0x8a2c0c;
	tab[6] = 0xb15318;
	tab[7] = 0xd17d39;
	tab[8] = 0xe5b686;
	tab[9] = 0xf8ecd3;
	tab[10] = 0xf1e9bf;
	tab[11] = 0xf8c95f;
	tab[12] = 0xffaa00;
	tab[13] = 0xcc8000;
	tab[14] = 0x995700;
	tab[15] = 0x6a3403;
	return (tab[f->nb_iter % 16]);
}

int	color_palette_four(t_fractal *f)
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
	functions for colors with bases and calculus
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
