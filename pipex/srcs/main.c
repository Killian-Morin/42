/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/20 09:45:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_files(char **argv)
{
	if (access(argv[1], F_OK) == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		open(argv[4], O_TRUNC);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		open(argv[4], O_TRUNC);
		exit(EXIT_FAILURE);
	}
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*p;

	if (argc != 5)
	{
		ft_putstr_fd("Sorry, not enough parameters\n", 2);
		return (1);
	}
	check_files(argv);
	p = malloc(sizeof(t_pipex));
	if (!p)
		exit(EXIT_FAILURE);
	init_pipex(p, argv, env);
	pipex(p, argv, env);
	clean(p);
	return (0);
}
