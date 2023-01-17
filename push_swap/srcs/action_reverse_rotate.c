/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_node;
	t_stack	*previous_last_node;

	last_node = (*stack_a);
	previous_last_node = NULL;
	while (last_node->next != NULL)
	{
		previous_last_node = last_node;
		last_node = last_node->next;
	}
	previous_last_node->next = NULL;
	last_node->next = (*stack_a);
	(*stack_a) = last_node;
	ft_putstr("rra\n");
}

// Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last_node;
	t_stack	*previous_last_node;

	last_node = (*stack_b);
	previous_last_node = NULL;
	while (last_node->next != NULL)
	{
		previous_last_node = last_node;
		last_node = last_node->next;
	}
	previous_last_node->next = NULL;
	last_node->next = (*stack_b);
	(*stack_b) = last_node;
	ft_putstr("rrb\n");
}

/*
rra et rrb en même temps
*/
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(&stack_a);
	reverse_rotate_b(&stack_b);
}
