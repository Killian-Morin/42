/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:45:36 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/19 15:01:19 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	a;
	int	b;
	int temp;

	temp = 0;
	a = 1;
	b = 2;	
	ft_swap(&a, &b);
	printf("a = %d \n", a);
	printf("b = %d", b);
	printf("%c", '\n');
	return (0);
}*/
