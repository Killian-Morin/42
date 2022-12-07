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

char	*get_next_line(int fd)
{
	int	count;
	char	buf[BUFFER_SIZE];
	static char	*stock;
	char	*temp;

	count = BUFFER_SIZE + 1;
	while (fd)
	{
		*buf++ = read(fd, buf, count);
		temp = buf;
		get_next_line(fd);
		if (buf == '\n')
		{
			temp = stock;
			temp = '\n';
			ft_putstr_fd(temp);
		}
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
