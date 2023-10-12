/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:56 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:45:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_len_hexadecimal(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_write_hexadecimal(unsigned int n, char type, int fd)
{
	int	len;

	len = ft_len_hexadecimal(n);
	if (n >= 16)
	{
		ft_write_hexadecimal(n / 16, type, fd);
		ft_write_hexadecimal(n % 16, type, fd);
	}
	else
	{
		if (n <= 9)
			ft_putnbr_fd(n, fd);
		else
		{
			if (type == 'x')
				ft_write_char((n - 10) + 'a', fd);
			if (type == 'X')
				ft_write_char((n - 10) + 'A', fd);
		}
	}
	return (len);
}
