/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:24:00 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/24 17:27:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == 0)
		res = 1;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 127)
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

	printf("%d\n", ft_str_is_printable(str));
	return (0);
}
