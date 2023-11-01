/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:20:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:25:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

char	*gnl_update_stock(char *stock)
{
	size_t		i;
	size_t		k;
	char		*str;

	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (stock[i] != '\n')
	{
		free(stock);
		return (NULL);
	}
	i++;
	str = (char *)malloc(sizeof(str) * (gnl_strlen(stock) - i + 1));
	if (!str)
	{
		free(stock);
		return (NULL);
	}
	k = 0;
	while (stock[i])
		str[k++] = stock[i++];
	str[k] = '\0';
	free(stock);
	return (str);
}

char	*gnl_line(char *stock)
{
	size_t	i;
	char	*line;

	i = 0;
	if (*stock == '\0')
		return (NULL);
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(line) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
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
	buffer = (char *)malloc(sizeof(buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(stock);
		return (NULL);
	}
	while (gnl_strchr(stock, '\n') != 1 && checker != 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
		{
			free(stock);
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
	static char	*stock[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = gnl_stock(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	line = gnl_line(stock[fd]);
	stock[fd] = gnl_update_stock(stock[fd]);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 0;
	while (i != 3)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		i++;
	}
	printf("\n\tnext fd\t\n");
	i = 0;
	while (i != 1)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		i++;
	}
	printf("\n\tnext fd\t\n");
	i = 0;
	while (i != 7)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
