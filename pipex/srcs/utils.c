/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/26 09:45:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_paths(t_pipex *p, char **env)
{
	int	i;

	i = 0;
	while (env[i++])
	{
		if (ft_strnstr(env[i], "PATH=", 5) == env[i])
		{
			p->path_env = ft_substr(env[i], 5, ft_strlen(env[i]));
			p->my_paths = ft_split_path(p->path_env, ':');
		}
	}
}

void	error_function(char *str, int err)
{
	perror(str);
	exit(err);
}

void	fd_close_all(t_pipex *p)
{
	close(p->infile);
	close(p->outfile);
	close(p->fd[0]);
	close(p->fd[1]);
}

void	clean(t_pipex *p)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (p->my_paths[i])
		free(p->my_paths[i++]);
	free(p->my_paths);
	while (p->cmd_arg[k])
		free(p->cmd_arg[k++]);
	free(p->cmd_arg);
	free(p->path_env);
	fd_close_all(p);
}
