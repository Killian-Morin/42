/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Décale d’une position vers le haut tous les élements de la stack passe en arg.
Le premier élément devient le dernier.

creer une var temp qui stocke le 1er node,
modif le 1er node pour qu'il pointe vers le second,
une var last_node qui stock le dernier node (trouve avec ft ds utils_stack.c);
fait pointer temp vers NULL puisque c'est maintenant le dernier node;
fait pointer last_node vers temp;
*/
static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	temp = *stack;
	*stack = (*stack)->next;
	last_node = find_last_node(*stack);
	temp->next = NULL;
	last_node->next = temp;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
