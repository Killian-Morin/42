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
Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
*/
void	reverse_rotate_a(t_stack *stack_a)
{
	int	data_last;

	data_last = last_node_data(stack_a);
	while (stack_a->next != NULL)
	{
		stack_a->next->data = stack_a->data;
		stack_a = stack_a->next;
	}
	stack_a->data = data_last;
	ft_putstr("rra\n");
}

/*
Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
*/
void	reverse_rotate_b(t_stack *stack_b)
{
	int	data_last;

	data_last = last_node_data(stack_b);
	while (stack_b->next != NULL)
	{
		stack_b->next->data = stack_b->data;
		stack_b = stack_b->next;
	}
	stack_b->data = data_last;
	ft_putstr("rrb\n");
}

/*
rra et rrb en même temps
*/
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
