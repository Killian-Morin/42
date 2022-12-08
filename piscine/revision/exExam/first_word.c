/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:41:30 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 13:47:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_word(char	*str)
{
	int	i;

	i = 0;
	while(str[i] != ' ' || str[i] != '\n' || str[i] != '\t' || str[i] != '\v' || str[i] != '\f' || str[i] != '\r')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1])
	{
		first_word(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}
