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

char	*gnl_new_stock(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	dest = malloc(sizeof(dest) * ft_strlen(str));
	if (!dest)
		return (NULL);
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*gnl_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(line) * (ft_strlen(str) + 1));
	if (!line)
		return (NULL);
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
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
	while (!ft_strchr(stock, '\n') && checker <= 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		else
		{
			buffer[checker] = '\0';
			stock = ft_strjoin(stock, buffer);
		}
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
	stock = gnl_new_stock(stock);
	free(stock);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if (line == NULL)
			break ;
	}
	return (0);
}
