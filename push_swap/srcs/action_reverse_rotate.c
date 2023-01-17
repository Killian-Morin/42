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

/*
Décale d’une position vers le bas tous les élements de la stack passe en arg.
Le dernier élément devient le premier.
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*previous_last_node;

	last_node = (*stack);
	previous_last_node = NULL;
	while (last_node->next != NULL)
	{
		previous_last_node = last_node;
		last_node = last_node->next;
	}
	previous_last_node->next = NULL;
	last_node->next = (*stack);
	(*stack) = last_node;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

/*
rra et rrb en même temps
*/
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(&stack_a);
	reverse_rotate(&stack_b);
	ft_putstr("rrr\n");
}