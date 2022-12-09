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

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = "";
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	int				i;
	char			*buffer[BUFFER_SIZE];
	char			*line;
	static char		*stock;

	i = 0;
	stock = "";
	line = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		stock[i] = buffer[i];
		if (ft_strchr(stock, '\n') != 0)
		{
			line = get_line(stock);
			return (line);
			stock = ft_strchr(stock, '\n');
		}
		i++;
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	n;

	n = (int)argv[argc];
	printf("%s\n", get_next_line(n));
	return (0);
}
