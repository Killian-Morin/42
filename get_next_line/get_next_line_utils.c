/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:22:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/12/06 10:26:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *stock, int c)
{
	size_t	i;

	i = 0;
	if (!stock)
	{
		free((char *)stock);
		return (NULL);
	}
	while (stock[i])
	{
		if (stock[i] == (char)c)
			return ((char *)stock + i);
		else
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

	size = gnl_strlen(stock) + gnl_strlen(buffer);
	str = malloc(sizeof(str) * (size + 1));
	if (!str)
	{
		free((char *)buffer);
		free((char *)stock);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (j != gnl_strlen(stock))
		str[j++] = stock[i++];
	i = 0;
	while (j != size)
		str[j++] = buffer[i++];
	str[j] = '\0';
	free((char *)buffer);
	free((char *)stock);
	return (str);
}

char	*gnl_update_stock(char *stock)
{
	size_t		i;
	size_t		k;
	char		*str;

	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (!stock)
	{
		free((char *)stock);
		return (NULL);
	}
	str = malloc(sizeof(str) * (gnl_strlen(stock) - i + 1));
	if (!str)
		return (NULL);
	i++;
	k = 0;
	while (stock[i])
		str[k++] = stock[i++];
	str[k] = '\0';
	free((char *)stock);
	return (str);
}
