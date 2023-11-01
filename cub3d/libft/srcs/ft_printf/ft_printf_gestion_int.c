/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:44:54 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:46:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_len_int(int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
		i = 1;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_len_int_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
		i = 1;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_write_integer(int n, int fd)
{
	int	len;

	len = ft_len_int(n);
	ft_putnbr_fd(n, fd);
	return (len);
}

int	ft_write_unsigned_integer(unsigned int n, int fd)
{
	int	len;

	len = ft_len_int_unsigned(n);
	if (n <= 4294967295 && n >= 10)
	{
		ft_write_unsigned_integer(n / 10, fd);
		ft_write_unsigned_integer(n % 10, fd);
	}
	else
		ft_putnbr_fd(n, fd);
	return (len);
}
