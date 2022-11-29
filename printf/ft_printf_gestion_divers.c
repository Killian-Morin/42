/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_divers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:55:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/29 17:01:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
