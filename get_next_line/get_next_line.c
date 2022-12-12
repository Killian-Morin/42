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
	line = malloc(sizeof(line) * (ft_strlen(str) + 1));
	if (!line)
		return (NULL);
	while (str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	int				checker;
	char			buffer[BUFFER_SIZE];
	char			*line;
	static char		*stock;

	stock = "";
	line = "";
	checker = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!(ft_strchr(stock, '\n')))
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
			return (NULL);
		else if (checker == 0)
			stock[checker] = '\0';
		if (stock == NULL)
			stock = buffer;
		else
			stock = ft_strjoin(stock, buffer);
	}
	line = get_line(stock);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		n;
	char	*line;

	n = (int)argv[argc];
	while (1)
	{
		line = get_next_line(n);
		printf("%s\n", line);
		free(line);
		if (line == NULL)
			break ;
	}
	return (0);
}
