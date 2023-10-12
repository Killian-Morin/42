/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:50:31 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:47:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf_which_format(const char *str, va_list args, int fd)
{
	int	len;

	len = 0;
	if (str[0] == 'c')
		len += ft_write_char(va_arg(args, int), fd);
	else if (str[0] == 's')
		len += ft_write_str(va_arg(args, char *), fd);
	else if (str[0] == 'p')
		len += ft_write_pointer(va_arg(args, uintptr_t), fd);
	else if (str[0] == 'd' || str[0] == 'i')
		len += ft_write_integer(va_arg(args, int), fd);
	else if (str[0] == 'u')
		len += ft_write_unsigned_integer(va_arg(args, unsigned int), fd);
	else if (str[0] == 'x' || str[0] == 'X')
		len += ft_write_hexadecimal(va_arg(args, unsigned int), str[0], fd);
	else if (str[0] == '%')
		len += ft_write_char('%', fd);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_printf_which_format(&str[i + 1], args, 1);
			i++;
		}
		else
			len += ft_write_char(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
