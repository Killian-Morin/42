/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b, int nb_element)
{
	if (nb_element == 2)
	{
		if (stack_a->data < stack_a->next->data)
			ft_putstr("\n");
		else
		{
			swap_a(stack_a);
			ft_putstr("sa\n");
		}
	}
	if (nb_element == 3)
		sort_three_element(stack_a);
	if (nb_element == 4)
		sort_four_element(stack_a, stack_b);
}

void	sort_three_element(t_stack *stack_a)
{
	if (stack_a->data < stack_a->next->data && stack_a->data < stack_a->next->next->data)
	{
		if (stack_a->next->data < stack_a->next->next->data)
			ft_putstr("\n");
		else
		{
			swap_a(stack_a);
			rotate_a(stack_a);
			ft_putstr("sa\nra\n");
		}
	}
	else if (stack_a->data > stack_a->next->data && stack_a->next->data < stack_a->next->next->data)
	{
		if (stack_a->data < stack_a->next->next->data)
		{
			swap_a(stack_a);
			ft_putstr("sa\n");
		}
		else
		{
			rotate_a(stack_a);
			ft_putstr("ra\n");
		}
	}
	else if (stack_a->data > stack_a->next->next->data && stack_a->next->data > stack_a->next->next->data)
	{
		if (stack_a->data < stack_a->next->data)
		{
			reverse_rotate_a(stack_a);
			ft_putstr("rra\n");
		}
		else
		{
			swap_a(stack_a);
			reverse_rotate_a(stack_a);
			ft_putstr("sa\nrra\n");
		}
	}
}

void	sort_four_element(t_stack *stack_a, t_stack *stack_b)
{
	push_b(stack_a, stack_b);
	ft_putstr("pb\n");
	sort_three_element(stack_a);
	push_a(stack_b, stack_a);
	ft_putstr("pa\n");
	if (stack_a->data < stack_a->next->data)
		ft_putstr("\n");
	//stack_a[1] < stack_a[0] < stack_a[2]
	else if (stack_a->data > stack_a->next->data && stack_a->data < stack_a->next->next->data)
	{
		swap_a(stack_a);
		ft_putstr("sa\n");
	}
	//stack_a[2] < stack_a[0] < stack_a[3]
	else if (stack_a->next->next->data < stack_a->data && stack_a->data > stack_a->next->next->next->data)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
		ft_putstr("rra\nsa\nra\nra\n");
	}
	//stack_a[3] < stack_a[0]
	else if (stack_a->next->next->next->data < stack_a->data)
	{
		rotate_a(stack_a);
		ft_putstr("ra\n");
	}
}
