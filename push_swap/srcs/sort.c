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

void	sort(t_stack **stack_a, t_stack **stack_b, int nb_elem)
{
	int	max;
	int	digits_max;
	int	i;

	max = find_max(*stack_a, nb_elem);
	digits_max = size_of_max(max);
	i = 0;
	while (i != digits_max)
	{
		radix_sort(stack_a, nb_elem, digits_max);
		i++;
	}
}

void	radix_sort(t_stack **stack_a, int nb_elem, int exp)
{
	int	tab[10];
	int	exp;

	digit = exp * 10;
	while ((*stack_a)->next != NULL)
	{
		tab[((*stack_a)->data % digit)] = (*stack_a)->data;
		(*stack_a) = (*stack_a)->next;
	}
}

int	find_max(t_stack *stack, int nb_elem)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i != nb_elem)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
		i++;
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
