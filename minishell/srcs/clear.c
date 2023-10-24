/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:22:31 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
free all lines of a malloc table, then free this table
*/
void	free_strs_table(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	tmp = NULL;
}

void	clear_redirection(t_redirection *cur)
{
	t_redirection	*tmp;

	tmp = cur;
	while (tmp)
	{
		tmp = tmp->next;
		free(cur->file_name);
		free(cur);
		cur = tmp;
	}
}

void	clear_all_commands(t_command *commands, int cmd_nbr)
{
	int	i;

	if (!commands)
		return ;
	i = 0;
	while (i != cmd_nbr)
	{
		clear_redirection(commands[i].infile);
		clear_redirection(commands[i].outfile);
		free_strs_table(commands[i].full_cmd);
		i++;
	}
	free(commands);
}

/*
free/reset all variables that where changed during the execution of a command
and that are needed for a following command
comme data->envp init avant loop, doit pas le reset et n'est pas free
*/
void	reset_after_exec_cmd(t_data *data)
{
	clear_tokens(data->tok);
	clear_all_commands(data->commands, data->cmd_nbr);
	free(data->user_input);
}
