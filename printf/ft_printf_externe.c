/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_externe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:56:52 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/28 15:49:55 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_write_int(int n)
{
	ft_putnbr_fd(n, 1);
}

void	ft_write_str(const char *s)
{
	while (*s)
	{
		ft_putchar_fd(*s, 1);
		s++;
	}
}

void	ft_int(int n, int base)
{
	if (n < 0)
	{
		n = n * -1;
		ft_write_char('-');
	}
	if (base == 10)
		ft_putnbr_fd(n, 1);
}
