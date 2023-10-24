/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:20:45 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	checker_loop(t_data *data)
{
	if (!data->tok)
	{
		free(data->user_input);
		clear_tokens(data->tok);
		return (1);
	}
	if (expansion_manager(data->tok, data->envp))
	{
		free(data->user_input);
		clear_tokens(data->tok);
		print_error("quotes not in right format", "expansion");
		return (1);
	}
	g_signal = 0;
	data->cmd_nbr = number_of_commands(data->tok);
	data->commands = init_commands(data->tok, data->cmd_nbr);
	if (!data->commands)
	{
		free(data->user_input);
		clear_tokens(data->tok);
		print_error("syntax error", "parser");
		return (1);
	}
	return (0);
}

void	loop(t_data *data)
{
	while (1)
	{
		data->user_input = readline("minishell > ");
		if (!data->user_input)
		{
			free_strs_table(data->envp);
			enable_print_termios();
			exit(g_signal);
		}
		if (data->user_input[0] != '\0')
			add_history(data->user_input);
		data->tok = tokenizer(data->user_input);
		if (checker_loop(data))
			continue ;
		execute(data);
		reset_after_exec_cmd(data);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	text_start();
	manage_sig(&data);
	disable_print_termios();
	g_signal = 0;
	data.envp = get_env(env, get_size_env(env));
	loop(&data);
	return (0);
}
