/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:03:23 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/25 11:19:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_printable(char	*str)
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
		if (str[i] >= 32 && str[i] <= 127)
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

	ft_str_is_printable(str);
	printf("%d \n", ft_str_is_printable(str));
}*/
