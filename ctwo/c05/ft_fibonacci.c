/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:39:38 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 11:59:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index > 1)
		index = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (index);
}

int	main(void)
{
	printf("%i\n", ft_fibonacci(6));
	return (0);
}
