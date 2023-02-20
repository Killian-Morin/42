/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min;
	int		signal;

	signal = 0;
	min = NULL;
	temp = *stack;
	while (temp)
	{
		if ((temp->index == -1) && (!signal || temp->data < min->data))
		{
			min = temp;
			signal = 1;
		}
		temp = temp->next;
	}
	return (min);
}

void	organize_stack(t_stack **stack)
{
	t_stack	*result;
	int		index;

	index = 0;
	result = get_next_min(stack);
	while (result)
	{
		result->index = index++;
		result = get_next_min(stack);
	}
	while ((*stack))
	{
		printf("%d\n", (*stack)->index);
		(*stack) = (*stack)->next;
	}
}

int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i != max_bits)
	{
		j = 0;
		while (j < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			push_a(stack_a, stack_b);
		i++;
	}
}
