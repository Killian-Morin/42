/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 09:12:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_julia(t_data img)
{
    t_complex   c;
    t_complex   new;
    t_complex   old;
	int		    i;
	int		    col;
	int		    row;

    c.x = -0.7;
    c.y = 0.27;
	col = 0;
	while (col++ != HEIGHT)
	{
		row = 0;
		while (row++ != WIDTH)
		{
            new.x = 1.5 * (col - WIDTH / 2) / (0.5 * WIDTH);
            new.y = (row - HEIGHT / 2) / (0.5 * HEIGHT);
            i = 0;
            while (i++ != 100)
            {
                old.x = new.x;
                old.y = old.y;
                new.x = old.x * old.x - old.y * old.y + c.x;
                new.y = 2 * old.x * old.y + c.y;
                if((new.x * new.x + new.y * new.y) > 4)
                    break;
            }
			if (i < 100)
				my_mlx_pixel_put(&img, col, row, 0x0);
			else
				my_mlx_pixel_put(&img, col, row, 0xffd700);
		}
	}
}