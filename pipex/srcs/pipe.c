/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:38:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init(t_pipex *p, char **argv, char **env)
{
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->infile < 0 || p->outfile < 0)
	{
		free(p);
		error("Error when opening a file");
	}
	p->my_paths = get_paths(env);
	if (p->my_paths == NULL)
	{
		free(p);
		error("Error the path has not been found");
	}
}

void	pipex(t_pipex *p, char **argv, char **env)
{
	if (pipe(p->fd) == -1)
		error_intermediate(p, "Error during the pipe");
	p->pid_child1 = fork();
	if (p->pid_child1 == -1)
		error_intermediate(p, "Error during the fork");
	else if (p->pid_child1 == 0)
	{
		p->cmd_arg = ft_split(argv[2], ' ');
		child_one(p, env);
	}
	p->pid_child2 = fork();
	if (p->pid_child2 == -1)
		error_intermediate(p, "Error during the fork");
	else if (p->pid_child2 == 0)
	{
		p->cmd_arg = ft_split(argv[3], ' ');
		child_two(p, env);
	}
	fd_close_two(p->fd[0], p->fd[1]);
	waitpid(p->pid_child1, NULL, 0);
	waitpid(p->pid_child2, NULL, 0);
	clean(p);
}

void	child_one(t_pipex *p, char **env)
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
		{
			is_last_path(p, cmd, i);
			free(cmd);
		}
		else if (execve(cmd, p->cmd_arg, env) == -1)
		{
			clean(p);
			error("Error with execve");
		}
	}
}

void	child_two(t_pipex *p, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
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
		{
			is_last_path(p, cmd, i);
			free(cmd);
		}
		else if (execve(cmd, p->cmd_arg, env) == -1)
		{
			clean(p);
			error("Error with execve");
		}
	}
}
