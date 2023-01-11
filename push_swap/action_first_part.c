/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_first_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:09:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/10 09:09:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *str)
{
	t_stack	*temp;

	if (ft_lstsize(str) >= 2)
	{
		temp[0] = str[1];
		str[1] = str[0];
		str[0] = temp[0];
	}
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		break ;
	else
	{
		temp[0] = stack_b[0];
		ft_lstadd_front(stack_a, temp);
		/*del stack_b[0] et monter tous ses elements de 1*/
	}
}
