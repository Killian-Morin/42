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

void	check_arg(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Sorry, not the right numbers of parameters\n", 2);
		exit(EXIT_FAILURE);
	}
}
/*
int	main(int argc, char **argv, char **env)
{
	t_pipex	*p;

	check_arg(argc);
	p = malloc(sizeof(p));
	if (!p)
		return (EXIT_FAILURE);
	init_fd(argv, p, env);
	return (0);
}*/
