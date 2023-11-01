/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:41:59 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/30 14:27:08 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	extension_check(char *s)
{
	char	*s1;

	s1 = ".cub\0";
	if (!ft_strncmp(s, "./", 2))
		s += 2;
	while (*s && *s != '.')
		s++;
	if (*s == '\0' || ft_strlen(s) != 4 || ft_strncmp(s, s1, 4) != 0)
		error_msg_exit("Invalid file extension.", "Please enter a .cub file.");
}

void	get_player_direction(char **map, t_player *p)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (is_on_player(p, map[y][x]))
			{
				p->pos_x = (double)x + 0.5;
				p->pos_y = (double)y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

/*
copy_content_to_list() remove all empty lines that might be at the start
of the .cub and copy all the remaining lines in a linked list

head_map is the first line of the map / after the elements of texture/colors
check_elements() parsed through all the elements for texture/colors and
arrived at the first line of the map
*/
void	parser(t_cub3d *data, char *av, t_list *head)
{
	t_list	*head_map;

	extension_check(av);
	head = copy_content_to_list(av);
	head_map = check_elements(&head, data);
	check_map(head_map, data);
	ft_lstclear(&head, del);
	get_player_direction(data->file.map, &data->p);
}

/*
for testing
	print_linked_list(&head);
	print_table2d(data->map);
	ft_lstclear(&head, del);
	free_tab(data->map);

void	print_linked_list(t_list **head)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = *head;
	printf("--------- LIST ---------\n");
	while (ptr)
	{
		printf("%d = %s\n", i, ptr->content);
		i++;
		ptr = ptr->next;
	}
	printf("------- END LIST -------\n");
}

void	print_table2d(char **s)
{
	int	i;

	i = 0;
	printf("--------- TAB2D ---------\n");
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
	printf("------- END TAB2D -------\n");
}
*/
