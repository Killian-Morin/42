/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_second_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:50:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/10 09:50:10 by kmorin           ###   ########.fr       */
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

void	reverse_rotate(t_stack *str)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = ft_lstsize(str);
	temp[0] = str[i];
	while (i != 0)
	{
		str[i - 1] = str[i];
		i--;
	}
	str[0] = temp[0];
}

void	reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
