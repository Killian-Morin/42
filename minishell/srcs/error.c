/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkukaqi <bkukaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:51:09 by bkukaqi           #+#    #+#             */
/*   Updated: 2023/07/21 13:51:09 by bkukaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error(char *msg, char *command)
{
	char	*base;

	if (command)
		base = ft_strjoin("minishell: ", command);
	else
		base = ft_strjoin("minishell: ", "unknown");
	if (errno && !msg)
	{
		g_signal = 1;
		perror(base);
	}
	else
	{
		ft_putstr_fd(base, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
		ft_putchar_fd('\n', 2);
	}
	free(base);
}

void	exit_error(char *msg, char *command, int code)
{
	print_error(msg, command);
	enable_print_termios();
	exit(code);
}
