/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:13:15 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/14 13:17:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		n = n * -1;
		ft_len(n);
		nb++;
	}
	while (n > 0)
	{
		ft_len(n / 10);
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_len(n);
	str = malloc(sizeof(str) * (j + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i] = 48;
	if (n < 0)
	{
		str[i] = '-';
		n = n * -1;
		ft_itoa(n);
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
