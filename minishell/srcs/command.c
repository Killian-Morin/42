/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:20:06 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*parse_one_command(t_command *cmd, t_token *tok)
{
	tok = manage_redirections(tok, cmd);
	tok = manage_strings(tok, cmd);
	if (!cmd->full_cmd)
	{
		cmd->full_cmd = malloc(sizeof(char *));
		if (!cmd->full_cmd)
			exit_error(NULL, "malloc failed", EX_OSERR);
		cmd->full_cmd[0] = NULL;
	}
	return (tok);
}

void	parse_commands(t_command *cmds, t_token *tok, int cmd_nbr)
{
	int	i;

	i = 0;
	while (cmds && i != cmd_nbr)
	{
		while (tok && tok->type != PIPE)
		{
			tok = parse_one_command(&cmds[i], tok);
		}
		if (tok && tok->type == PIPE)
		{
			if (!tok->next)
				g_signal = ERR_PARSER;
			tok = tok->next;
		}
		i++;
	}
}

t_command	*init_commands(t_token *tok, int cmd_nbr)
{
	t_command	*tmp;
	int			i;

	tmp = malloc(sizeof(t_command) * cmd_nbr);
	if (!tmp)
		exit_error(NULL, "malloc failed", EX_OSERR);
	i = 0;
	while (i != cmd_nbr)
	{
		tmp[i].infile = NULL;
		tmp[i].outfile = NULL;
		tmp[i].full_cmd = NULL;
		i++;
	}
	parse_commands(tmp, tok, cmd_nbr);
	if (g_signal == ERR_PARSER)
	{
		clear_all_commands(tmp, cmd_nbr);
		g_signal = 258;
		return (NULL);
	}
	return (tmp);
}
