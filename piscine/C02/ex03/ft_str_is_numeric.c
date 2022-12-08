/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:43:09 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/25 11:12:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_numeric(char	*str)
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
		if (str[i] >= '0' && str[i] <= '9')
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

	ft_str_is_numeric(str);
	printf("%d \n", ft_str_is_numeric(str));
}*/
