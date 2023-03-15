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
# include <stdint.h>
# include "./libft.h"

int			ft_printf(const char *str, ...);
int			ft_printf_which_format(const char *str, va_list args);

int			ft_write_char(char c);
int			ft_write_str(char *s);

int			ft_write_hexadecimal(unsigned int n, char type);
int			ft_len_hexadecimal(unsigned int n);

int			ft_write_integer(int n);
int			ft_len_int(int n);
int			ft_len_int_unsigned(unsigned int n);
int			ft_write_unsigned_integer(unsigned int n);

int			ft_len_pointer(uintptr_t ptr);
int			ft_write_pointer(uintptr_t ptr);

void		ft_put_ptr(uintptr_t ptr);

#endif
