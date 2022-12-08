/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/25 11:15:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_lowercase(char	*str)
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
		if (str[i] >= 'a' && str[i] <= 'z')
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

	ft_str_is_lowercase(str);
	printf("%d \n", ft_str_is_lowercase(str));
}*/
