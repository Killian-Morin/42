/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/08 09:45:00 by kmorin           ###   ########.fr       */
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
