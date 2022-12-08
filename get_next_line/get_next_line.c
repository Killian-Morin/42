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

void	ft_line(char *temp)
{
	char	*line;
	int		k;
	int		l;

	k = 0;
	l = 0;
	line = "";
	while (temp[k] != '\n')
		line[l++] = temp[k++];
	line[l] = '\n';
	ft_putstr_fd(line, 1);
}

static char	*ft_temp(char *buf, int count)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = "";
	while (i <= count)
	{
		temp[j++] = *buf;
		i++;
	}
	if (temp[j] == '\n')
		ft_line(temp);
	return (temp);
}

char	*get_next_line(int fd)
{
	int			i;
	char		buf[BUFFER_SIZE];
	char		*line;
	static char	*temp;

	i = 0;
	temp = "";
	line = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{
		buf[i++] = read(fd, buf, BUFFER_SIZE);
		temp = ft_temp(buf, BUFFER_SIZE);
		get_next_line(fd);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	n;

	n = (int)argv[argc];
//	printf("%d\n", open("myfile.txt", O_RDONLY)); pour connaitre fd du fichier test
	printf("%s\n", get_next_line(n));
	return (0);
}
