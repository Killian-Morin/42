/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:22:01 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 08:26:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
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
		printf("%d\n", ft_str_is_lowercase(argv[1]));
	return (0);
}
