/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/24 09:45:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_pipex(t_pipex *p, char **argv, char **env)
{
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->infile < 0 || p->outfile < 0)
		error_function("Error when opening a file", 0);
	get_paths(p, env);
}

void	pipex(t_pipex *p, char **argv, char **env)
{
	if (pipe(p->fd) == -1)
		error_function("Error when opening the pipe", 0);
	p->pid = fork();
	if (p->pid == -1)
		error_function("Error during the fork", 0);
	else if (p->pid == 0)
		child_process(p, argv, env);
	else
		parent_process(p, argv, env);
}

void	child_process(t_pipex *p, char **argv, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	if (dup2(p->infile, STDIN_FILENO) == -1
		|| dup2(p->fd[1], STDOUT_FILENO) == -1)
		error_function("Error when redirecting a fd", 0);
	close(p->fd[0]);
	close(p->infile);
	p->cmd_arg = ft_split(argv[2], ' ');
	while (p->my_paths[i])
	{
		cmd = ft_strjoin(p->my_paths[i], p->cmd_arg[0]);
		if (access(cmd, X_OK) == -1)
		{
			free(cmd);
			i++;
		}
		else
			execve(cmd, p->cmd_arg, env);
	}
}

void	parent_process(t_pipex *p, char **argv, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	waitpid(p->pid, NULL, 0);
	if (dup2(p->fd[0], STDIN_FILENO) == -1
		|| dup2(p->outfile, STDOUT_FILENO) == -1)
		error_function("Error when redirecting a fd", 0);
	close(p->fd[1]);
	close(p->outfile);
	p->cmd_arg = ft_split(argv[3], ' ');
	while (p->my_paths[i])
	{
		cmd = ft_strjoin(p->my_paths[i], p->cmd_arg[0]);
		if (access(cmd, X_OK) == -1)
		{
			free(cmd);
			i++;
		}
		else
			execve(cmd, p->cmd_arg, env);
	}
}
