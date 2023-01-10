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

void	swap_a(t_stack *stack_a)
{
	t_stack	*temp;

	if (ft_lstsize(stack_a) >= 2)
	{
		temp[0] = stack_a[1];
		stack_a[1] = stack_a[0];
		stack_a[0] = temp[0];
	}
}

void	swap_b(t_stack *stack_b)
{
	t_stack	*temp;

	if (ft_lstsize(stack_b) >= 2)
	{
		temp[0] = stack_b[1];
		stack_b[1] = stack_b[0];
		stack_b[0] = temp[0];
	}
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		break ;
	else
	{
		temp[0] = stack_b[0];
		ft_lstadd_front(stack_a, temp);
		//del stack_b[0] et monter tous ses elements de 1
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		break ;
	else
	{
		temp[0] = stack_a[0];
		ft_lstadd_front(stack_b, temp);
		//del stack_a[0] et monter tous ses elements de 1
	}
}
