/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:56 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/29 17:29:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexadecimal(unsigned int n, char type)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_write_hexadecimal(n / 10, type);
		ft_write_hexadecimal(n % 10, type);
	}
	else
	{
		if (n <= 9)
		{
			ft_write_integer(n);
			len++;
		}
		else
		{
			if (type == 'x')
				ft_write_char((n - 10) + 'a');
			if (type == 'X')
				ft_write_char((n - 10) + 'A');
			len++;
		}
	}
	return (len);
}
