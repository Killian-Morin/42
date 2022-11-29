/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_ptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:53:58 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/29 17:30:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_pointer(void *ptr)
{
	int	len;

	len = 0;
	ft_write_char('0');
	ft_write_char('x');
	ft_write_hexadecimal((int)ptr, 'x');
	return (len + 2);
}
