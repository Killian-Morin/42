/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:45:46 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/24 16:52:33 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == 0)
		res = 1;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 112)
			res = 1;
		else
			return (0);
		i++;
	}
	return (res);
}

int	main(void)
{
	char	str[] = "blabla";

	printf("%i\n", ft_str_is_lowercase(str));
	return (0);
}
