/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcargv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:23:28 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/23 13:42:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		write(1, tableau, 30);
	}
	else if (argc > 2)
	{
		write(2, "Erreur : format incorrect (trop d'arguments)\n", 45);
	}
	else
	{
		write(2, "Erreur : format incorrect (pas assez d'arguments)\n", 50);
	}
}
