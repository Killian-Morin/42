/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:29:13 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
used write instead of printf since in the list of safe function to use
in signal handlers
*/
void	handler_sigint(int i)
{
	(void)i;
	if (g_signal == -1)
	{
		write(1, "\n", 1);
		g_signal = 130;
	}
	else
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler_sigquit(int i)
{
	(void)i;
	if (g_signal == -1)
	{
		write(1, "Quit: 3\n", 8);
		g_signal = 131;
	}
	else
		rl_redisplay();
}

/*
use of ft_bzero() to make sure that each bits of the struct are init to 0
particular treatment for ^C in handler_sigint and for ^\ in handler_sigquit
*/
void	manage_sig(t_data *data)
{
	struct sigaction	sig;

	ft_bzero(&sig, sizeof(struct sigaction));
	sig.sa_handler = &handler_sigint;
	if (sigaction(SIGINT, &sig, &data->sig_old) == -1)
		printf("sigint error");
	sig.sa_handler = &handler_sigquit;
	if (sigaction(SIGQUIT, &sig, &data->sig_old) == -1)
		printf("sigquit error");
}

/*
gives back the default running for SIGINT and SIGQUIT
*/
void	restore_sig(t_data *data)
{
	if (sigaction(SIGINT, &data->sig_old, NULL) == -1)
		printf("sigint error");
	if (sigaction(SIGQUIT, &data->sig_old, NULL) == -1)
		printf("sigquit error");
}

/*
ignore the ^C and ^\
*/
void	ignore_sig(void)
{
	struct sigaction	sig;

	ft_bzero(&sig, sizeof(struct sigaction));
	sig.sa_handler = SIG_IGN;
	if (sigaction(SIGINT, &sig, NULL) == -1)
		printf("sigint error");
	if (sigaction(SIGQUIT, &sig, NULL) == -1)
		printf("sigquit error");
}
