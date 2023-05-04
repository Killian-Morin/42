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

char	**get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) == env[i])
			return (ft_split_path(&env[i][5], ':'));
		else
			i++;
	}
	return (NULL);
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
	free(p);
	fd_close_all(p);
}
