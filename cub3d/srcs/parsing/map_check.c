/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:02:52 by mdanchev          #+#    #+#             */
/*   Updated: 2023/11/01 10:59:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cara_checker(t_file *f)
{
	int	x;
	int	y;

	y = 0;
	while (y != f->map_max_y)
	{
		x = 0;
		while (x != f->map_max_x)
		{
			if (is_valid_char(f->map[y][x]) == true)
				x++;
			else
			{
				free_tab_size(f->map, f->map_max_y);
				free_texture_file(f);
				error_msg_exit("Map error:", \
					"Map contains forbidden caracters.");
			}
		}
		y++;
	}
}

void	nb_player_checker(t_file *f)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (y != f->map_max_y)
	{
		x = 0;
		while (x != f->map_max_x)
		{
			if (f->map[y][x] == 'N' || f->map[y][x] == 'S' || \
				f->map[y][x] == 'E' || f->map[y][x] == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
	{
		free_tab_size(f->map, f->map_max_y);
		free_texture_file(f);
		error_msg_exit("Map error:", "Number of players is incorrect: need 1.");
	}
}

void	remove_empty_lines_after_map(t_list **head)
{
	t_list	*last;
	t_list	*prev;
	int		size;
	int		i;

	last = ft_lstlast(*head);
	while (is_empty_line(last->content) == true)
	{
		i = 0;
		size = ft_lstsize(*head) - 1;
		prev = *head;
		while (i < size - 1)
		{
			prev = prev->next;
			i++;
		}
		prev->next = NULL;
		ft_lstdelone(last, del);
		last = ft_lstlast(*head);
	}
}

void	check_empty_line_in_map(t_list *map, t_cub3d *data)
{
	while (map->next)
	{
		if (is_empty_line(map->content) == true)
		{
			free_texture_file(&data->file);
			error_msg_exit("Map error:", "Empty lines in map definition.");
		}
		map = map->next;
	}
}

/*
	added check_empty_line_map() since empty lines were kept in the list,
	we are now at the node where the map definition start and we check
	if there is an empty line present until meeting the end of the map
*/
void	check_map(t_list *head_map, t_cub3d *data)
{
	t_list	*map_node;

	remove_empty_lines_after_map(&head_map);
	check_empty_line_in_map(head_map, data);
	map_node = head_map;
	get_map_size_list(map_node, &data->file);
	copy_map(map_node, &data->file);
	cara_checker(&data->file);
	change_map(&data->file);
	walls_checker(&data->file);
	nb_player_checker(&data->file);
}
