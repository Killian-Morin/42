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

void	get_path(t_pipex *p, char **env)
{
	p->path_env = ft_substr(env[4], 5, 100);
	p->my_paths = ft_split_path(p->path_env, ':');
}

void	get_av(t_pipex *p, char **argv, int ac)
{
	p->cmd_arg = ft_split(argv[ac], ' ');
}
