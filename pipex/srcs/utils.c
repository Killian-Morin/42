/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:38:46 by kmorin           ###   ########.fr       */
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

void	fd_close_two(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	fd_close_all(t_pipex *p)
{
	close(p->infile);
	close(p->outfile);
	close(p->fd[0]);
	close(p->fd[1]);
}

void	clean_char_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

void	clean(t_pipex *p)
{
	clean_char_tab(p->my_paths);
	free(p->cmd_arg);
	fd_close_all(p);
	free(p);
}
