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

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
	}
	else
	{
		ft_putstr_fd("Sorry, not enough parameters\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
