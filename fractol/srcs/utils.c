/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
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

int	ft_determine_color(t_fractal *f)
{
	if (f->signal_color == 1)
		return (color_palette_one(f));
	if (f->signal_color == 2)
		return (color_palette_two(f));
	if (f->signal_color == 3)
		return (color_palette_three(f));
	if (f->signal_color == 4)
		return (color_palette_four(f));
	return (color_palette_five(f));
}
