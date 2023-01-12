/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *str)
{
	t_stack	*temp;
	int		i;

	temp[0] = str[0];
	i = 1;
	while (i != ft_lstsize(str))
	{
		str[i - 1] = str[i];
		i++;
	}
	str[i] = temp[0];
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}