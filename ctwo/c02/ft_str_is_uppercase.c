/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:19:23 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/24 17:23:43 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == 0)
		res = 1;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			res = 1;
		else
			return (0);
		i++;
	}
	return (res);
}

int	main(void)
{
	char	str[] = "";

	printf("%i\n", ft_str_is_uppercase(str));
	return (0);
}
