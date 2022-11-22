/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:45:59 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/22 15:21:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_int(int arg, ...)
{
	int		i;
	int		x;
	va_list	ap;

	i = 0;
	va_start(ap, arg);
	while (i < arg)
	{
		x = va_arg(ap, int);
		ft_itoa(x);
    	i++;
	}
	va_end(ap);
	return (x);
}

int	main(void)
{
	int	num;

	num = 10;
	ft_int(num, 21, 48);
	return (0);
}

