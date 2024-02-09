/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:22:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/02/09 14:30:23 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	gnl_strchr(char *stock, int c)
{
	size_t	i;

	i = 0;
	if (!stock)
		return (0);
	while (stock[i])
	{
		if (stock[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
	{
		s = (char *)malloc(sizeof(char) * 1);
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	str = (char *)malloc(sizeof(str) * ((gnl_strlen(s) + gnl_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	i = 0;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free(s);
	return (str);
}
