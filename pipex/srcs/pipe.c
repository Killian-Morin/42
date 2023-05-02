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

void	start(t_pipex *p, char **argv, char **env)
{
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (p->infile < 0 || p->outfile < 0)
		return (perror("Error when opening a file: \n"));
	get_path(p, env);
	pipex(p, argv, env);
}

void	pipex(t_pipex *p, char **argv, char **env)
{
	if (pipe(p->fd) == -1)
		return (perror("Error when opening the pipe: \n"));
	p->pid = fork();
	if (p->pid == -1)
		return (perror("Error during the fork: \n"));
	if (p->pid == 0)
		child_process(p, argv, env);
	else
		parent_process(p, argv, env);
}

void	child_process(t_pipex *p, char **argv, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	if (dup2(p->infile, STDIN_FILENO) == -1)
		return (perror("Error when redirecting a fd: \n"));
	if (dup2(p->fd[1], STDOUT_FILENO) == -1)
		return (perror("Error when redirecting a fd: \n"));
	close(p->fd[0]);
	close(p->infile);
	get_av(p, argv, 2);
	while (p->my_paths[i++])
	{
		cmd = ft_strjoin(p->my_paths[i], p->cmd_arg[0]);
		execve(cmd, p->cmd_arg, env);
		free(cmd);
	}
	free(p->cmd_arg[0]);
	free(p->cmd_arg[1]);
	free(p->cmd_arg);
}

void	parent_process(t_pipex *p, char **argv, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	waitpid(p->pid, NULL, 0);
	if (dup2(p->fd[0], STDIN_FILENO) == -1)
		return (perror("Error when redirecting a fd: \n"));
	if (dup2(p->outfile, STDOUT_FILENO) == -1)
		return (perror("Error when redirecting a fd: \n"));
	close(p->fd[1]);
	close(p->outfile);
	get_av(p, argv, 3);
	while (p->my_paths[i++])
	{
		cmd = ft_strjoin(p->my_paths[i], p->cmd_arg[0]);
		execve(cmd, p->cmd_arg, env);
		free(cmd);
	}
	free(p->cmd_arg[0]);
	free(p->cmd_arg[1]);
	free(p->cmd_arg);
}
