/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:38:43 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_files(char **argv)
{
	if (access(argv[1], F_OK) == -1)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		open(argv[4], O_TRUNC);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		open(argv[4], O_TRUNC);
		exit(EXIT_FAILURE);
	}
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
	{
		ft_putstr_fd("permission denied: ", 2);
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
		if (argc < 5)
			ft_putstr_fd("Sorry, not enough parameters\n", 2);
		else
			ft_putstr_fd("Sorry, too many parameters\n", 2);
		return (1);
	}
	check_files(argv);
	p = malloc(sizeof(t_pipex));
	if (!p)
		exit(EXIT_FAILURE);
	init(p, argv, env);
	pipex(p, argv, env);
	return (0);
}
