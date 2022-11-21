/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:08:46 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/24 16:34:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == 0)
		res = 1;
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			res = 1;
		else
		{
			res = 0;
			return (res);
		}
		i++;
	}
	return (res);
}

int	main(void)
{
	char	str[] = "fdsaf4a";

	printf("%i\n", ft_str_is_alpha(str));
	return (0);
}
