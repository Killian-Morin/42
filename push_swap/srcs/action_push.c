/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
*/
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*new_node;

	if (!stack_a)
		return ;
	new_node = stack_b->next;
	stack_b->next = stack_a;
	stack_a = stack_b;
	stack_b = new_node;
	new_node = NULL;
}

/*
Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
*/
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*new_node;

	if (!stack_a)
		return ;
	new_node = stack_a->next;
	stack_a->next = stack_b;
	stack_b = stack_a;
	stack_a = new_node;
	new_node = NULL;
}
