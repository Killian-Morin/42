/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	digits_max;

	max = find_max(*stack_a);
	digits_max = size_of_max(max);
	radix_sort_units(stack_a, stack_b);
	radix_sort(stack_a, stack_b, digits_max);
}

//for the units rank
void	radix_sort_units(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	while ((*stack_a) != NULL)
	{
		node = (*stack_a);
		rotate_a(stack_a);
		while ((node->data % 10) > ((*stack_a)->data % 10))
			rotate_a(stack_a);
		push_b(stack_b, stack_a);
		if ((*stack_a)->next == NULL)
			push_b(stack_b, stack_a);
	}
	// printf("fin radix_sort_units\n");
}

//for the dizaines rank and above
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int digits_max)
{
	t_stack	*node;
	int		i;
	int		exp;

	i = 1;
	exp = 10;
	while (ft_lstsize(*stack_b) != 1)
	{
		reverse_rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
	while (i != digits_max)
	{
		if (stack_is_sorted(*stack_a) == 0)
			return ;
		else
		{
			node = (*stack_a);
			node->data -= node->data % 10;
			node->data /= exp;
			node->data %= 10;
			rotate_a(stack_a);
			while (node->data > (*stack_a)->data)
				rotate_a(stack_a);
			push_b(stack_b, stack_a);
			if ((*stack_a)->next == NULL)
				push_b(stack_b, stack_a);
		}
		i++;
		exp *= 10;
	}
}

int	find_max(t_stack *stack)
{
	int	max;

	max = 0;
	while (stack->next != NULL)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	size_of_max(int max)
{
	int	i;

	i = 1;
	if (max < 0)
		max *= -1;
	while (max > 10)
	{
		max /= 10;
		i++;
	}
	return (i);
}
