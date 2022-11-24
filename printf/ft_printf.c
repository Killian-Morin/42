/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:50:31 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/24 15:54:53 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(char c)
{
	write(1, &c, 1);
}

void	ft_write_int(int x)
{
	write(1, &x, 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		temp;
	int		status;
	int		integer;
	char	cara;
	va_list	arg;

	i = 0;
	status = 0;
	va_start(arg, str);
	while (i < (int)arg)
	{
		if (status == 0)
		{
			if (*str == '%')
				status = 1;
			else
				ft_write_char(*str);
		}
		else if (status == 1)
		{
			temp = va_arg(arg, int);
			if (ft_isascii(temp) == 1)
			{
				cara = va_arg(arg, int);
				ft_write_char(cara);
			}
			else if (ft_isdigit(temp) == 1)
			{
				integer = va_arg(arg, int);
				ft_write_int(integer);
			}
		}
		i++;
		temp = 0;
		status = 0;
	}
	va_end(arg);
	return (0);
}

int	main(void)
{
	const char	*s;

	s = "les arguments variadiques commencent apres cet argument";
	ft_printf(s, 'a');
	ft_printf(s, '1');
	ft_printf(s, '%');
	ft_putchar_fd('\n', 1);
	return (0);
}
