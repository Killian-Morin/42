/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:33:20 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	text_start(void)
{
	printf("\e[0;33m-------------------------------------\n");
	printf("|\t     MINISHELL\t\t    |\n");
	printf("-------------------------------------\n\e[0;39m");
}

void	cmd_to_lower(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			str[i][j] = ft_tolower(str[i][j]);
			j++;
		}
		i++;
	}
}

void	check_status(int status)
{
	if (WIFEXITED(status))
		g_signal = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (g_signal == 130 || g_signal == 131)
			return ;
		g_signal = 128 + WTERMSIG(status);
		if (g_signal == 138)
			print_error("bus error", "execution");
		if (g_signal == 139)
			print_error("segmentation fault", "execution");
	}
}

int	size_of_command(t_token *tok)
{
	int	i;

	i = 0;
	while (tok && tok->type != PIPE)
	{
		if (is_string(tok->type))
			i++;
		tok = tok->next;
	}
	return (i);
}
