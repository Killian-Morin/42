/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:55:30 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	in_redirection(t_command *cmd)
{
	t_redirection	*previous;

	if (!cmd->infile)
		return (0);
	previous = NULL;
	while (cmd->infile)
	{
		if (previous)
			close(cmd->infile_fd);
		cmd->infile_fd = open(cmd->infile->file_name, O_RDONLY);
		if (cmd->infile_fd < 0)
		{
			print_error(NULL, cmd->infile->file_name);
			return (1);
		}
		previous = cmd->infile;
		cmd->infile = cmd->infile->next;
		dup2(cmd->infile_fd, STDIN_FILENO);
	}
	return (0);
}

int	create_out_file(t_command *cmd, t_redirection *previous)
{
	if (previous)
		close(cmd->outfile_fd);
	if (cmd->outfile->append == 3)
	{
		cmd->outfile_fd = open(cmd->outfile->file_name,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (cmd->outfile_fd < 0)
		{
			print_error(NULL, cmd->outfile->file_name);
			return (1);
		}
	}
	else if (cmd->outfile->append == 1)
	{
		cmd->outfile_fd = open
			(cmd->outfile->file_name,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd->outfile_fd < 0)
		{
			print_error(NULL, cmd->outfile->file_name);
			return (1);
		}
	}
	return (0);
}

int	out_redirection(t_command *cmd)
{
	t_redirection	*previous;

	if (!cmd->outfile)
		return (0);
	previous = NULL;
	while (cmd->outfile)
	{
		if (create_out_file(cmd, previous))
			return (1);
		previous = cmd->outfile;
		cmd->outfile = cmd->outfile->next;
		dup2(cmd->outfile_fd, STDOUT_FILENO);
	}
	return (0);
}

/*
called to close the files descriptor of a solo builtin
*/
void	close_redirections(t_command *cmd)
{
	if (cmd->infile)
		close(cmd->infile_fd);
	if (cmd->outfile)
		close(cmd->outfile_fd);
}
