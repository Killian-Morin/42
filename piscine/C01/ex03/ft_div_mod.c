/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:31:11 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/19 12:26:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	temp1;
	int	temp2;

	temp1 = a / b;
	temp2 = a % b;
	*div = temp1;
	*mod = temp2;
}
/*
int	main(void)
{
	int	div;
	int	mod;

	ft_div_mod(11, 5, &div, &mod);
	printf("resultat division : %d \n", div);
	printf("resultat modulo : %d", mod);
	printf("%c", '\n');
	return (0);
}*/
