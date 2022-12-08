/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:37:07 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/25 11:10:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_alpha(char	*str)
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
		if ((str[i] >= 'A'
				&& str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
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

	ft_str_is_alpha(str);
	printf("%d \n", ft_str_is_alpha(str));
}*/
