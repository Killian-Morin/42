/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkukaqi <bkukaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:56:04 by bkukaqi           #+#    #+#             */
/*   Updated: 2023/07/17 16:56:04 by bkukaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirection_pipe(t_data *data, int i)
{
	if (i > 0 && !data->commands[i].infile)
		dup2(data->commands[i - 1].fd[0], STDIN_FILENO);
	if (i < (data->cmd_nbr - 1))
	{
		if (!data->commands[i].outfile)
			dup2(data->commands[i].fd[1], STDOUT_FILENO);
	}
}

void	close_all_pipes(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		if (close(data->commands[j].fd[0]) == -1)
			print_error(NULL, "close pipe in");
		if (close(data->commands[j].fd[1]) == -1)
			print_error(NULL, "close pipe out");
		j++;
	}
}
