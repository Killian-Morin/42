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
}

/*
    to use instead of mlx_pixel_put | mimic its behaviour
    calculate the offset of the pixels to align them correctly
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_absolute(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}
