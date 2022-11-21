/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:35:02 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/24 16:45:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == 0)
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = 1;
		else
			res = 0;
		i++;
	}
	return (res);
}

int	main(void)
{
	char	str[] = "83293";

	printf("%i\n", ft_str_is_numeric(str));
	return (0);
}
