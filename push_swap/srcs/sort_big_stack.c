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

int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->data;
	max_bits = 0;
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		*tab;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	tab = fill_tab_increasing(stack_a);
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			tab = fill_tab_increasing(stack_a);
			if (((*tab >> i) & 1) == 1)
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

int	*fill_tab_increasing(t_stack **stack_a)
{
	int		i;
	int		j;
	int		temp;
	int		*number;
	t_stack	*lol;

	i = 0;
	lol = *stack_a;
	number = malloc(sizeof(number) * ft_lstsize(*stack_a));
	while (i != ft_lstsize(*stack_a))
	{
		number[i] = lol->data;
		i++;
		lol = lol->next;
	}
	i = 0;
	while (i < ft_lstsize(*stack_a))
	{
		j = i + 1;
		while (j < ft_lstsize(*stack_a))
		{
			if (number[i] > number[j])
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
			++j;
		}
		++i;
	}
	return (number);
}

t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	organize_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
	while ((*stack))
	{
		printf("%d\n", (*stack)->index);
		(*stack) = (*stack)->next;
	}
}
