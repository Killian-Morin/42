/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:37:29 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/29 17:28:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);

int	ft_write_char(char c);
int	ft_write_str(char *s);

int	ft_write_hexadecimal(unsigned int n, char type);

int	ft_write_integer(int n);
int	ft_write_unsigned_integer(unsigned int n);

int	ft_write_pointer(void *ptr);

#endif
