/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:20:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/12/06 10:25:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*gnl_line(char *stock)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	line = malloc(sizeof(line) * (i + 2));
	if (!line)
		return (NULL);
	while (stock[i] != '\0' && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_stock(int fd, char *stock)
{
	int		checker;
	char	*buffer;

	checker = 1;
	buffer = malloc(sizeof(buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!gnl_strchr(stock, '\n') && checker != 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[checker] = '\0';
		stock = gnl_strjoin(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = gnl_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = gnl_line(stock);
	stock = gnl_update_stock(stock);
	return (line);
}
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
