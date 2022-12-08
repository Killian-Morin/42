/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:30:42 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 08:34:42 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 127)
		{
			ret = 1;
			i++;
		}
		else
			return (0);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1])
		printf("%d\n", ft_str_is_printable(argv[1]));
	return (0);
}
