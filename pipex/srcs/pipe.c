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
	{
		free(p);
		error("Error when opening a file");
	}
	p->my_paths = get_paths(env);
}

void	pipex(t_pipex *p, char **argv, char **env)
{
	if (pipe(p->fd) == -1)
	{
		fd_close_all(p);
		free(p);
		error("Error when opening the pipe");
	}
	p->pid = fork();
	if (p->pid == -1)
	{
		fd_close_all(p);
		free(p);
		error("Error during the fork");
	}
	else if (p->pid == 0)
	{
		p->cmd_arg = ft_split(argv[2], ' ');
		child_process(p, env);
	}
	else
	{
		p->cmd_arg = ft_split(argv[3], ' ');
		parent_process(p, env);
	}
}

void	child_process(t_pipex *p, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	if (dup2(p->infile, STDIN_FILENO) == -1
		|| dup2(p->fd[1], STDOUT_FILENO) == -1)
	{
		clean(p);
		error("Error when redirecting a fd");
	}
	fd_close_two(p->outfile, p->fd[0]);
	while (p->my_paths[i++])
	{
		cmd = ft_strjoin(p->my_paths[i], p->cmd_arg[0]);
		if (access(cmd, X_OK & F_OK) == -1)
			free(cmd);
		else if (execve(cmd, p->cmd_arg, env) == -1)
		{
			clean(p);
			error("Error with execve");
		}
	}
	free(cmd);
}

void	parent_process(t_pipex *p, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	waitpid(p->pid, NULL, 0);
	if (dup2(p->fd[0], STDIN_FILENO) == -1
		|| dup2(p->outfile, STDOUT_FILENO) == -1)
	{
		clean(p);
		error("Error when redirecting a fd");
	}
	fd_close_two(p->infile, p->fd[1]);
	while (p->my_paths[i++])
	{
		cmd = ft_strjoin(p->my_paths[i], p->cmd_arg[0]);
		if (access(cmd, X_OK & F_OK) == -1)
			free(cmd);
		else if (execve(cmd, p->cmd_arg, env) == -1)
		{
			clean(p);
			error("Error with execve");
		}
	}
	free(cmd);
}
