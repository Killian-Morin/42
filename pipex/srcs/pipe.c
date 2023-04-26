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
	if (access(p->av[4], F_OK) == 0)
		p->fd_outfile = open(p->av[4], O_WRONLY);
	else
		p->fd_outfile = open(p->av[4], O_CREAT);
	if (p->fd_infile < 0 || p->fd_outfile < 0)
		return (perror("Error when opening a file"));
	ft_find_path(p, env);
	// printf("%s\n", p->path);
	pipex(p, env);
}

void	pipex(t_pipex *p, char **env)
{
	int		fd[2];
	pid_t	parent;

	pipe(fd);
	parent = fork();
	if (parent == -1)
		return (perror("Error during the fork: "));
	if (parent == 0)
		child_process(p, fd, env);
	else
		parent_process(p, fd, env);
}

void	child_process(t_pipex *p, int fd[2], char **env)
{
	(void)env;
	dup2(p->fd_infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(p->fd_infile);
	execve(p->path, p->av, env);
}

void	parent_process(t_pipex *p, int fd[2], char **env)
{
	int	stat_loc;

	(void)env;
	waitpid(-1, &stat_loc, 0);//wait for the child process
	dup2(p->fd_outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(p->fd_outfile);
	execve(p->path, p->av, env);
}
