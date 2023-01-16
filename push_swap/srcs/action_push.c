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

stack_a est la dest
stack_b est la src
*/
void	push_a(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*new_node;

	if (!stack_src)
		return ;
	new_node = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = new_node;
	ft_putstr("pa\n");
}

/*
Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.

stack_a est la src
stack_b est la dest
*/
void	push_b(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*new_node;

	if (!stack_src)
		return ;
	new_node = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = new_node;
	ft_putstr("pb\n");
}
