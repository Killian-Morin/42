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
	int	j;
	int	*tab;

	i = 0;
	j = min;
	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(tab) * (max - min));
	if (!tab)
		return (NULL);
	while (i != (max - min))
	{
		tab[i] = j;
		i++;
		j++;
	}
	return (tab);
}
/*
int	main(void)
{
	int	i;
	int	*tab;

	i = 0;
	tab = ft_range(10, 20);
	while (i != 10)
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0);
}*/
