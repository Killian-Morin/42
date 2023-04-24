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
void	init_fd(char **argv, t_pipex *p, char **env)
{
	p->fd_infile = open(argv[1], O_RDONLY);
	if (access(argv[4], F_OK) == 0)
		p->fd_outfile = open(argv[4], O_WRONLY);
	else
		p->fd_outfile = open(argv[4], O_CREAT);
	if (p->fd_infile < 0 || p->fd_outfile < 0)
		return (perror("Problem when opening a file"));
	pipex(p, env);
}

void	pipex(t_pipex *p, char **env)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent == -1)
		return (perror("Fork: "));
	if (parent == 0)
		child_process(p, end, env);
	else
		parent_process(p, end, env);
}

void	child_processs(t_pipex *p, int end[2], char **env)
{
	dup2(p->fd_infile, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(p->fd_infile);
	//exec
}

void	parent_process(t_pipex *p, int end[2], char **env)
{
	int	stat_loc;

	waitpid(-1, &stat_loc, 0);//wait for the child process
	dup2(p->fd_outfile, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(p->fd_outfile);
	//exec
}
