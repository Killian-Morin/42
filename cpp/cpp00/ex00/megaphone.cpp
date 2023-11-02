/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:25:45 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/01 13:41:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int	i;
		int	j;
		for (i = 1; av[i]; i++)
		{
			for (j = 0; av[i][j]; j++)
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] = toupper(av[i][j]);
			}
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
}
