/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:55:43 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/25 11:17:42 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_uppercase(char	*str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == '\0')
	{
		res = 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			res = 1;
		}
		else
		{
			res = 0;
			return (res);
		}
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	char	str[] = "";

	ft_str_is_uppercase(str);
	printf("%d \n", ft_str_is_uppercase(str));
}*/
