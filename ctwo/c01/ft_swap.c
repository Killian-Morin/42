/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:41:09 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/24 12:48:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 10;
	ft_swap(&a, &b);
	printf("%i\n", a);
	printf("%i", b);
	return (0);
}
