/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:28:52 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:08 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_info_redir(t_redirection **files, char *name, int append)
{
	t_redirection	*new;
	t_redirection	*tmp;

	new = malloc(sizeof(t_redirection));
	if (!new)
		exit_error(NULL, "malloc failed", EX_OSERR);
	new->next = NULL;
	new->append = append;
	new->file_name = ft_strdup(name);
	if (!*files)
	{
		*files = new;
		return ;
	}
	tmp = *files;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	get_redirections(t_token *tok, t_command *cur_command)
{
	if (!tok->next || !is_string(tok->next->type))
	{
		g_signal = ERR_PARSER;
		return (1);
	}
	if (tok->type == REDIR_IN || tok->type == HERE_DOC)
		add_info_redir(&cur_command->infile, tok->next->content, tok->type);
	else if (tok->type == REDIR_OUT || tok->type == REDIR_OUT_APPEND)
		add_info_redir(&cur_command->outfile, tok->next->content, tok->type);
	return (0);
}

t_token	*manage_redirections(t_token *tok, t_command *cur_command)
{
	t_token	*save;

	save = tok;
	while (tok && tok->type != PIPE)
	{
		if (is_redir(tok->type))
		{
			if (get_redirections(tok, cur_command))
				return (NULL);
			tok->type = IGNORE;
			tok->next->type = IGNORE;
			tok = tok->next->next;
		}
		else
			tok = tok->next;
	}
	return (save);
}

t_token	*get_strings(t_token *tok, t_command *cur_command)
{
	int	size;
	int	i;

	i = 0;
	size = size_of_command(tok);
	cur_command->full_cmd = malloc(sizeof(char *) * (size + 1));
	if (!cur_command->full_cmd)
		exit_error(NULL, "malloc failed", EX_OSERR);
	while (tok && i < size)
	{
		if (!tok->content || tok->type == IGNORE)
		{
			tok = tok->next;
			continue ;
		}
		cur_command->full_cmd[i] = ft_strdup(tok->content);
		tok = tok->next;
		i++;
	}
	cur_command->full_cmd[i] = NULL;
	return (tok);
}

t_token	*manage_strings(t_token *tok, t_command *cur_command)
{
	while (tok && tok->type != PIPE)
	{
		if (is_string(tok->type))
			tok = get_strings(tok, cur_command);
		else
			tok = tok->next;
		if (g_signal == ERR_PARSER)
			return (NULL);
	}
	return (tok);
}
