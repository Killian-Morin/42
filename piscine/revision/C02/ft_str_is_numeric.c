/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:16:49 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 08:21:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
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
		printf("%d\n", ft_str_is_numeric(argv[1]));
	return (0);
}
