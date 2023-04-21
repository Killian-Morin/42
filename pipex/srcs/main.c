/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/20 09:45:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	start(char **argv, char **env)
{
	int	infile;
	int	outfile;

	infile = open(argv[1], O_RDONLY);
	if (access(argv[4], F_OK) == 0)
		outfile = open(argv[4], O_WRONLY);
	else
		outfile = open(argv[4], O_CREAT);
	dup2(outfile, STDOUT_FILENO);
	if (!ft_strncmp(argv[2], "ls", 3))
		execve("/bin/ls", &argv[2], env);
	if (!ft_strncmp(argv[2], "echo", 5))
		execve("/bin/echo", &argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
		start(argv, env);
	else
	{
		ft_putstr_fd("Sorry, not the right numbers of parameters\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
