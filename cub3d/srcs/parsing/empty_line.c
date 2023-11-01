/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:44:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/27 13:41:32 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

bool	is_space(char c)
{
	if (c == 32)
		return (true);
	return (false);
}

bool	is_empty_line(char *s)
{
	if (*s == '\n')
		return (true);
	while (*s && is_whitespace(*s) == true)
		s++;
	if (!*s)
		return (true);
	return (false);
}

/*
	removed the use of head since when this function is called,
	head is still empty so there is no need to ft_lstclear() it,
	if there was an error

	will remove the empty lines that might be at the start of the .cub
*/
char	*remove_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	if (!line)
		error_msg_exit("get_next_line error or empty file", NULL);
	return (line);
}

/*
	replaced by a simple line = get_next_line(fd) in create_linked_list()
	since this function was removing the empty lines that might be between
	the element AND the ones INSIDE THE MAP if there was some,
	but empty lines in the map definition is an error

char	*remove_empty_lines2(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (line);
}*/
