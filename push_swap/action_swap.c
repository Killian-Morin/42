/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	temp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = temp;
	free(temp);
}

void	swap_b(t_stack *stack_b)
{
	int	temp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	temp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = temp;
	free(temp);
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}