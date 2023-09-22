/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:31:54 by killian           #+#    #+#             */
/*   Updated: 2023/09/15 11:41:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
disable the echo of terminal special characters from the input like ^C/^D/^\
*/
void	disable_print_termios(void)
{
	struct termios	config;

	tcgetattr(STDIN_FILENO, &config);
	config.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &config);
}

/*
enable the echo of terminal special characters from the input like ^C/^D/^\
*/
void	enable_print_termios(void)
{
	struct termios	config;

	tcgetattr(STDIN_FILENO, &config);
	config.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &config);
}
