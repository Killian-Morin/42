/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:50:31 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/28 17:16:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas_part(const char *str, int index)
{
	if (str[index + 1] == '%')
		ft_write_char('%');
}

int	ft_printf_principale(const char *str, va_list args)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				ft_write_char('%');
			if (str[i + 1] == 'c')
				ft_write_char(va_arg(args, int));
			if (str[i + 1] == 'i' || str[i + 1] == 'd')
				ft_write_int(va_arg(args, int));
			i++;
		}
		else
			ft_write_char(str[i]);
		i++;
	}
	ft_write_char('\n');
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_printf_principale(str, args);
	va_end(args);
	return (0);
}

int	main(void)
{
//	void	*pointer_to_main = (void *) main;

	ft_printf("Print a character: %c", '0');
//	ft_printf("Print a string: %s", "Hello World");
//	ft_printf("Print a pointer: %p", pointer_to_main);
	ft_printf("Print a number: %d %d", 10, 11);
	ft_printf("Print a number: %i %i", 10, 11);
//	ft_printf("Print an unsigned integer: %u", -10);
//	ft_printf("Print an hex integer with minuscules: %x", 10);
//	ft_printf("Print an hex integer with majuscules: %X", 10);
	ft_printf("Print a percentage: %% %%");
	return (0);
}
