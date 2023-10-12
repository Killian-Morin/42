/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gestion_divers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:55:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:44:19 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_write_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_write_str(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_write_str("(null)", fd);
		return (6);
	}
	while (s[i])
	{
		ft_write_char(s[i], fd);
		i++;
	}
	return (i);
}
