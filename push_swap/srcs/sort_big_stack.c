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

void	divide_big_stack(t_stack **stack_a, t_stack **stack_b, int nb_elem)
{
	while (nb_elem != nb_elem / 2)
	{
		push_b(stack_b, stack_a);
		nb_elem--;
	}
}

void	reassemble_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->next != NULL)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		(*stack_b) = (*stack_b)->next;
	}
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b, int nb_elem)
{
	int	max;
	int	nb_of_digits;

	max = find_max_data(*stack_a);
	nb_of_digits = size_of_max(max);
	divide_big_stack(stack_a, stack_b, nb_elem);
	sort(stack_a, stack_b, nb_elem);
	reassemble_big_stack(stack_a, stack_b);
	printf("max: %d\n", max);
	printf("digits: %d\n", nb_of_digits);
}

int	find_max_data(t_stack *stack)
{
	int	max;

	max = 0;
	while (stack && stack->next != NULL)
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
	while (max > 10)
	{
		max = max / 10;
		i++;
	}
	return (i);
}
