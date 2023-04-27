/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/24 09:45:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
	with this manner
	maybe make a function exec previous to that one
	with a struct with all var needed for the prog (fd_1/2, the cmd)
	in this function I initialize all variables needed
*/
void	init_fd(t_pipex *p, char **env)
{
	p->fd_infile = open(p->av[1], O_RDONLY);
	p->fd_outfile = open(p->av[4], O_WRONLY | O_CREAT, 0777);
	if (p->fd_infile < 0 || p->fd_outfile < 0)
		return (perror("Error when opening a file\n"));
	// ft_find_path(p, env);
	// printf("%s\n", p->path);
	pipex(p, env);
}

void	pipex(t_pipex *p, char **env)
{
	pid_t	parent;

	if (pipe(p->fd) == -1)
		return (perror("Error when opening the pipe: \n"));
	parent = fork();
	if (parent == -1)
		return (perror("Error during the fork: \n"));
	if (parent == 0)
		child_process(p, env);
	else
		parent_process(p, env);
}

void	child_process(t_pipex *p, char **env)
{
	(void)env;
	dup2(p->fd_infile, STDIN_FILENO);
	dup2(p->fd[1], STDOUT_FILENO);
	close(p->fd[0]);
	close(p->fd_outfile);
	execve(p->path, p->av, env);
	close(p->fd[1]);
}

void	parent_process(t_pipex *p, char **env)
{
	int	stat_loc;

	(void)env;
	waitpid(-1, &stat_loc, 0);//wait for the child process
	dup2(p->fd_outfile, STDOUT_FILENO);
	dup2(p->fd[0], STDIN_FILENO);
	// printf("infile: %d\n fd[1]: %d\n", p->fd_infile, p->fd[1]);
	// printf("outfile: %d\n fd[0]: %d\n", p->fd_outfile, p->fd[0]);
	close(p->fd[1]);
	close(p->fd_infile);
	execve(p->path, p->av, env);
	close(p->fd[0]);
}
