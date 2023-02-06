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
	digits_max = size_of_max(max) + 1;
	radix_sort_units(stack_a, stack_b);
	printf("%d\n%d\n%p\n", (*stack_b)->data, (*stack_b)->next->data, (*stack_b)->next->next);
	// radix_sort(stack_a, stack_b, digits_max);
}

//for the units rank
void	radix_sort_units(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	while ((*stack_a) != NULL)
	{
		node = (*stack_a);
		node->data %= 10;
		(*stack_a) = (*stack_a)->next;
		while (node->data <= ((*stack_a)->data % 10))
			rotate_a(stack_a);
		push_b(stack_b, stack_a);
		printf("b : %d\n", (*stack_b)->data);
		printf("a : %d\n", (*stack_a)->data);
	}
	printf("ca passe\n");
}

//for the dizaines rank and above
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int digits_max)
{
	t_stack	**temp;
	t_stack	*node;
	int		i;
	int		exp;

	i = 1;
	exp = 10;
	while (i != digits_max)
	{
		temp = stack_a;
		while ((*stack_a)->next != NULL)
		{
			node = (*stack_a);
			node->data = node->data - (node->data % 10);
			node->data /= exp;
			node->data %= 10;
			while ((*stack_a)->next != NULL)
			{
				if (node->data <= (*stack_a)->data)
				{
					while ((*temp)->data != node->data)
					{
						rotate_a(temp);
						(*temp) = (*temp)->next;
					}
					push_b(stack_b, temp);
				}
				(*stack_a) = (*stack_a)->next;
			}
			(*stack_a) = (*stack_a)->next;
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

	if (max < 0)
		i = 0;
	else
		i = 1;
	while (max > 10)
	{
		max = max / 10;
		i++;
	}
	return (i);
}
