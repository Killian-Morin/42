/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_divers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:55:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:35:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_write_str("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_write_char(s[i]);
		i++;
	}
	return (i);
}
