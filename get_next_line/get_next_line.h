/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:21:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/12/06 10:24:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_line(char *str);
char	*gnl_stock(int fd, char *str);
char	*gnl_new_stock(char *str);

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
