/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:38:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_intermediate(t_pipex *p, char *str)
{
	fd_close_all(p);
	clean_char_tab(p->my_paths);
	free(p);
	error(str);
}

void	is_last_path(t_pipex *p, char *cmd, int i)
{
	if (access(cmd, X_OK & F_OK) == -1 && p->my_paths[i + 1] == NULL)
		error("Command not found");
}
