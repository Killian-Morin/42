/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:55:53 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/03 13:11:23 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (0);
	tab = (int*)malloc(sizeof(int*) * (max - min));
	if (!tab)
		return (0);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

int	main(void)
{
	int	i = 0;
	int	*tab;

	tab = ft_range(10, 20);
	while (i < (20 - 10))
	{
		printf("%i\n", *tab);
		i++;
	}
	return (0);
}
