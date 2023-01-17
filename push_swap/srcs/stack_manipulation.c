/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*add_first_node(int value)
{
	t_stack	*new_node;
	t_stack	*head;

	head = NULL;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = head;
	head = new_node;
	return (new_node);
}

void	add_node_bottom(t_stack *stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		free(stack);
	new_node->data = value;
	last = find_last_node(stack);
	last->next = new_node;
	new_node->next = NULL;
}

t_stack	*find_last_node(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*find_previous_last_node(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
