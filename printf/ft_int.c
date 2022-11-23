/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:31:54 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/23 15:38:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_writeint(int num_args, ...)
{
	int		i;
	int		res;
	va_list	arg;

	i = 0;
	va_start(arg, num_args);
	while (i > (int)arg)
	{
		res = va_arg(arg, int);
		ft_itoa(res);
		write(1, &res, 1);
		i++;
	}
	va_end(arg);
}
