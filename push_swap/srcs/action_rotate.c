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

#include "../includes/push_swap.h"

/*
Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
*/
void	rotate_a(t_stack **stack_a)
{
	t_stack *first_node;
	t_stack *last_node;

	first_node = (*stack_a);
	last_node = (*stack_a);

	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	(*stack_a) = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	ft_putstr("ra\n");
}

/*
Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
*/
void	rotate_b(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack *last_node;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last_node = find_last_node(*stack_b);
	temp->next = NULL;
	last_node->next = temp;
	ft_putstr("rb\n");
}

/*
ra et rb en même temps
*/
void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
