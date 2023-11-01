/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:27:33 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/27 14:38:46 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_which_missing(t_cub3d *data, t_list *node)
{
	if (data->cond.no == 0)
		parser_error_exit(node->content, \
			"Missing definition of the north texture.", data);
	if (data->cond.so == 0)
		parser_error_exit(node->content, \
			"Missing definition of the south texture.", data);
	if (data->cond.we == 0)
		parser_error_exit(node->content, \
			"Missing definition of the west texture.", data);
	if (data->cond.ea == 0)
		parser_error_exit(node->content, \
			"Missing definition of the east texture.", data);
	if (data->cond.c == 0)
		parser_error_exit(node->content, \
			"Missing definition of the ceiling color.", data);
	if (data->cond.f == 0)
		parser_error_exit(node->content, \
			"Missing definition of the floor color.", data);
}

void	check_multiple_declaration(enum e_id key, t_list *node, t_cub3d *data)
{
	if (key == NO && data->cond.no == 1)
		parser_error_exit(node->content,
			"Multiple definitions of the north texture.", data);
	if (key == SO && data->cond.so == 1)
		parser_error_exit(node->content, \
			"Multiple definitions of the south texture.", data);
	if (key == EA && data->cond.ea == 1)
		parser_error_exit(node->content, \
			"Multiple definitions of the east texture.", data);
	if (key == WE && data->cond.we == 1)
		parser_error_exit(node->content, \
			"Multiple definitions of the west texture.", data);
	if (key == C && data->cond.c == 1)
		parser_error_exit(node->content, \
			"Multiple definitions of the ceiling color.", data);
	if (key == F && data->cond.f == 1)
		parser_error_exit(node->content, \
			"Multiple definitions of the floor color.", data);
}

/*
	added the if since the empty lines between lines are kept in the linked list
	if one is found, we simply pass to the next node
*/
bool	check_get_elements(char *s, t_list *node, t_cub3d *data)
{
	int	i;

	if (is_empty_line(node->content) == true)
		return (true);
	i = 0;
	while (s[i] && is_whitespace(s[i]) == true)
		i++;
	if (!ft_strncmp("NO ", &s[i], 3))
		return (get_texture_file(&s[i] + 3, NO, node, data));
	else if (!ft_strncmp("SO ", &s[i], 3))
		return (get_texture_file(&s[i] + 3, SO, node, data));
	else if (!ft_strncmp("WE ", &s[i], 3))
		return (get_texture_file(&s[i] + 3, WE, node, data));
	else if (!ft_strncmp("EA ", &s[i], 3))
		return (get_texture_file(&s[i] + 3, EA, node, data));
	else if (!ft_strncmp("F ", &s[i], 2))
		return (get_color(&s[i] + 2, F, node, data));
	else if (!ft_strncmp("C ", &s[i], 2))
		return (get_color(&s[i] + 2, C, node, data));
	return (false);
}

t_list	*check_elements(t_list **head_element, t_cub3d *data)
{
	t_list	*node;

	data->cond = (t_cond){};
	node = *head_element;
	while (node && check_get_elements(node->content, node, data) == true)
		node = node->next;
	if (check_cond_flag(&data->cond))
		check_which_missing(data, node);
	if (!node)
	{
		ft_lstclear(head_element, del);
		free_texture_file(&data->file);
		error_msg_exit("PARSER stopped because the map is missing.", NULL);
	}
	return (node);
}
