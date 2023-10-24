/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Décale d’une position vers le bas tous les élements de la stack passe en arg.
Le dernier élément devient le premier.

creer le node last_node qui stock le 1er node,
creer le node previous_last_node qui est initalise a NULL pour le moment;
itere tout le long de la liste en attribuant 
le node ou l'on est a previous_last_node et en iterant sur last_node;
quand le dernier node atteint, on fait pointer l'avant dernier node vers NULL;
on fait pointer last_node vers le 1er node;
ainsi l'avant dernier node devient le dernier et le dernier le 1er;
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

void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(&stack_a);
	reverse_rotate(&stack_b);
	ft_putstr("rrr\n");
}
