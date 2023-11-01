/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:52:50 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/26 11:04:46 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
// La fonction del qui doit être dans la libft
void    del(void *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}
*/

t_list	*create_head(char *line)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (!node)
		error_msg_exit("ft_lstnew: malloc error", NULL);
	return (node);
}

void	join_new_node(t_list **node, t_list **head, char *line)
{
	*node = ft_lstnew(NULL);
	if (!*node)
	{
		ft_lstclear(head, del);
		free(line);
		error_msg_exit("ft_lstnew: malloc", NULL);
	}
	ft_lstadd_back(head, *node);
}

void	create_linked_list(t_list *node, t_list **head, int fd, char *line)
{
	while (line != NULL)
	{
		node->content = ft_strtrim(line, "\n");
		if (!node->content)
		{
			del(line);
			ft_lstclear(head, del);
			error_msg_exit("ft_strtrim: malloc error", NULL);
		}
		del(line);
		line = get_next_line(fd);
		if (line)
			join_new_node(&node, head, line);
	}
}

int	open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(RED "Error\nThe file ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(" was not open.\nCause: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(WHITE "\n", 2);
		exit(1);
	}
	return (fd);
}

t_list	*copy_content_to_list(char *s)
{
	int		fd;
	t_list	*head;
	char	*line;

	head = NULL;
	fd = open_file(s);
	line = remove_empty_lines(fd);
	head = create_head(NULL);
	create_linked_list(head, &head, fd, line);
	close(fd);
	return (head);
}
