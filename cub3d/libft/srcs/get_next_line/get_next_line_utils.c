/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:22:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:25:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

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

char	*gnl_strjoin(char *stock, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!stock)
	{
		stock = (char *)malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	size = gnl_strlen(stock) + gnl_strlen(buffer);
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (stock[i])
		str[j++] = stock[i++];
	i = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}
