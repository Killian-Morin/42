/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
/*
int ft_keyboard(int keycode, t_vars *vars)
{
    if (keycode == 0)//a
        changer le c.re de julia
    if (keycode == 2)//d
        changer le c.im de julia
    if (keycode == 123)//left arrow
        deplacer vers la gauche x--
    if (keycode == 124)//right arrow
        deplacer vers la droite x++
    if (keycde == 125)//down arrow
        deplacer vers le bas y--
    if (keycode == 126)//up arrow
        deplacer vers le haut y++
    return (0);
}*/
