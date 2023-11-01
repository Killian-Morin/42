/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:37:29 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:45:24 by kmorin           ###   ########.fr       */
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

/* ft_printf.c */
int			ft_printf(const char *str, ...);
int			ft_printf_which_format(const char *str, va_list args, int fd);

/* ft_printf_gestion_divers.c */
int			ft_write_char(char c, int fd);
int			ft_write_str(char *s, int fd);

/* ft_printf_gestion_hex.c */
int			ft_write_hexadecimal(unsigned int n, char type, int fd);
int			ft_len_hexadecimal(unsigned int n);

/* ft_printf_gestion_int.c */
int			ft_write_integer(int n, int fd);
int			ft_len_int(int n);
int			ft_len_int_unsigned(unsigned int n);
int			ft_write_unsigned_integer(unsigned int n, int fd);

/* ft_printf_gestion_ptr.c */
int			ft_len_pointer(uintptr_t ptr);
int			ft_write_pointer(uintptr_t ptr, int fd);
void		ft_put_ptr(uintptr_t ptr, int fd);

/* ft_dprintf.c */
int			ft_dprintf(int fd, const char *str, ...);

#endif
