/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:37:29 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/28 17:10:13 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

void	ft_write_char(char c);
void	ft_write_int(int n);
void	ft_write_str(const char *s);
int		ft_printf(const char *str, ...);

#endif
