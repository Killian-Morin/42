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

int	ft_mouse(int mousecode)
{
	t_pos	pos;

	if (mousecode == 4)
		pos.zoom++;
	if (mousecode == 5)
		pos.zoom--;
	return (0);
}
