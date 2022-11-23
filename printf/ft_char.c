/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:49:39 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/23 15:37:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_writechar(int num_args, ...)
{
	int		i;
	char	res;
	va_list	arg;

	i = 0;
	va_start(arg, num_args);
	while (i > (int)arg)
	{
		res = va_arg(arg, int);
		write(1, &res, 1);
		i++;
	}
	va_end(arg);
}
