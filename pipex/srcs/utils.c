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

/*
    function if necessary that will display the error message,
    for the case where the command is not found
    might add in argument the command passed to put it in the error message
*/
void	ft_error(void)
{
	ft_putstr_fd("zsh: command not found: ", 25);
}

void	ft_find_path(t_pipex *p, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = "PATH=";
	while (env[i] != tmp)
		i++;
	printf("%d\n", i);
	p->path = ft_substr(env[i], 5, 1);
}
