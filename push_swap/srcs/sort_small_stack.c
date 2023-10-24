/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		sort_three_element(stack_a);
	if (ft_lstsize(*stack_a) == 4)
		sort_four_element(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 5)
		sort_five_element(stack_a, stack_b);
}

void	sort_three_element(t_stack **st_a)
{
	if ((*st_a)->data < (*st_a)->next->data && (*st_a)->data < (*st_a)
		->next->next->data && (*st_a)->next->data < (*st_a)->next->next->data)
		return ;
	else if ((*st_a)->data < (*st_a)->next->data && (*st_a)->data < (*st_a)
		->next->next->data && (*st_a)->next->data > (*st_a)->next->next->data)
	{
		swap_a(*st_a);
		rotate_a(st_a);
	}
	else if ((*st_a)->data < (*st_a)->next->data && (*st_a)->data > (*st_a)
		->next->next->data && (*st_a)->next->data > (*st_a)->next->next->data)
		reverse_rotate_a(st_a);
	else if ((*st_a)->data > (*st_a)->next->data && (*st_a)->data < (*st_a)
		->next->next->data && (*st_a)->next->data < (*st_a)->next->next->data)
		swap_a(*st_a);
	else if ((*st_a)->data > (*st_a)->next->data && (*st_a)->data > (*st_a)
		->next->next->data && (*st_a)->next->data > (*st_a)->next->next->data)
	{
		swap_a(*st_a);
		reverse_rotate_a(st_a);
	}
	else if ((*st_a)->data > (*st_a)->next->data && (*st_a)->data > (*st_a)
		->next->next->data && (*st_a)->next->data < (*st_a)->next->next->data)
		rotate_a(st_a);
}

void	sort_four_element(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_b, stack_a);
	sort_three_element(stack_a);
	push_a(stack_a, stack_b);
	if ((*stack_a)->data < (*stack_a)->next->data)
		return ;
	else if ((*stack_a)->data < (*stack_a)->next->next->data)
		swap_a(*stack_a);
	else if ((*stack_a)->data < (*stack_a)->next->next->next->data)
	{
		reverse_rotate_a(stack_a);
		swap_a(*stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->next->data)
		rotate_a(stack_a);
}

void	sort_five_element(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_b, stack_a);
	sort_four_element(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->data < (*stack_a)->next->data)
		return ;
	else if ((*stack_a)->data < (*stack_a)->next->next->data)
		swap_a(*stack_a);
	else if ((*stack_a)->data < (*stack_a)->next->next->next->data)
	{
		reverse_rotate_a(stack_a);
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->next->next->next->data)
	{
		reverse_rotate_a(stack_a);
		swap_a(*stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->next->next->data)
		rotate_a(stack_a);
}
