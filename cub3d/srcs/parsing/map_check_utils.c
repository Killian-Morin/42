/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:22:39 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/27 14:41:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '1')
		return (true);
	return (false);
}

void	get_map_size_list(t_list *map_node, t_file *file)
{
	file->map_max_y = ft_lstsize(map_node);
	file->map_max_x = 0;
	while (map_node)
	{
		if (file->map_max_x < (int)ft_strlen(map_node->content))
			file->map_max_x = (int)ft_strlen(map_node->content);
		map_node = map_node->next;
	}
}

char	*cpy_str(char *str, int size)
{
	int		i;
	char	*s;

	s = malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	while (i != size)
		s[i++] = '-';
	s[i] = '\0';
	return (s);
}

void	copy_map(t_list *map_node, t_file *file)
{
	int		i;

	file->map = malloc(sizeof(char *) * (file->map_max_y + 1));
	if (!file->map)
	{
		free_texture_file(file);
		error_msg_exit("malloc failed when copying map", NULL);
	}
	i = 0;
	while (map_node)
	{
		file->map[i++] = cpy_str(map_node->content, file->map_max_x);
		map_node = map_node->next;
	}
	file->map[i] = NULL;
}

void	change_map(t_file *file)
{
	int	x;
	int	y;

	y = 0;
	while (y != file->map_max_y)
	{
		x = 0;
		while (x != file->map_max_x)
		{
			if (is_space(file->map[y][x]) == true)
				file->map[y][x] = '-';
			x++;
		}
		y++;
	}
}
