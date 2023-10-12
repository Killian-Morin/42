/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_ptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:53:58 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:47:04 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_len_pointer(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16, fd);
		ft_put_ptr(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_putnbr_fd(ptr, fd);
		else
			ft_write_char((ptr - 10) + 'a', fd);
	}
}

int	ft_write_pointer(uintptr_t ptr, int fd)
{
	int	len;

	len = 2;
	ft_write_str("0x", fd);
	if (ptr == 0)
		len += ft_write_char('0', fd);
	else
	{
		ft_put_ptr(ptr, fd);
		len += ft_len_pointer(ptr);
	}
	return (len);
}
