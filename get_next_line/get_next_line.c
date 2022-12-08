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
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

int	check_end_of_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	else
		i++;
	return (0);
}

char	*get_next_line(int fd)
{
	int				cara_to_read;
	int				i;
	static char		*buffer[BUFFER_SIZE];
	char			*line;
	static char		*stock;

	cara_to_read = BUFFER_SIZE;
	i = 0;
	stock = "";
	line = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, buffer, cara_to_read) != 0)
	{
		stock[i++] = read(fd, buffer, cara_to_read);
		if (check_end_of_line(stock) == 1)
			line = get_line(stock);
		else
			get_next_line(fd);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	n;

	n = (int)argv[argc];
	printf("%s\n", get_next_line(n));
	return (0);
}
