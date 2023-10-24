/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:08 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:40:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_error_numeric(t_data *data, char *s)
{
	char	*str;

	str = ft_strjoin("exit: ", s);
	print_error("numeric argument required", str);
	free(str);
	restore_redirections_builtin(data);
	enable_print_termios();
	exit(255);
}

void	check_valid_arg(t_data *data, char *s)
{
	int	j;

	if (s[0] != '+' && s[0] != '-' && !ft_isdigit(s[0]))
		exit_error_numeric(data, s);
	if ((s[0] == '+' || s[0] == '-') && !s[1])
		exit_error_numeric(data, s);
	j = 1;
	while (s[j])
	{
		if (!ft_isdigit(s[j]))
			exit_error_numeric(data, s);
		j++;
	}
}

int	ft_exit(t_data *data, int i)
{
	int	n;

	printf("exit\n");
	if (!data->commands[i].full_cmd[1])
	{
		restore_redirections_builtin(data);
		enable_print_termios();
		exit(g_signal);
	}
	check_valid_arg(data, data->commands[i].full_cmd[1]);
	n = ft_atoi(data->commands[i].full_cmd[1]);
	if (n > 255)
		n %= 256;
	if (data->commands[i].full_cmd[1] && data->commands[i].full_cmd[2])
	{
		g_signal = 1;
		print_error("too many arguments", "exit");
		return (0);
	}
	restore_redirections_builtin(data);
	enable_print_termios();
	exit (n);
}
