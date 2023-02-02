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
	int	*tab;

	max = find_max(*stack_a);
	digits_max = size_of_max(max) + 1;
	tab = radix_sort_units(stack_a);
	radix_sort(stack_a, tab, digits_max);
}

//for the units rank
int	*radix_sort_units(t_stack **stack_a)
{
	int	*tab;
	int	temp;

	temp = 0;
	tab = malloc(sizeof(tab) * 10);
	if (!tab)
		return (NULL);
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->data < 0)
		{
			temp = (*stack_a)->data;
			temp = ((temp * -1) % 10);
			tab[temp] = (*stack_a)->data;
		}
		else
		{
			temp = (*stack_a)->data;
			temp %= 10;
			tab[temp] = (*stack_a)->data;
		}
		(*stack_a) = (*stack_a)->next;
	}
	return (tab);
}

//for the dizaines rank and above
void	radix_sort(t_stack **stack_a, int *units_sorted, int digits_max)
{
	int	tab[10];
	int	nb_of_pass;
	int	i;
	int	exp;
	int	temp;

	nb_of_pass = 1;
	exp = 10;
	temp = 0;
	while (nb_of_pass != digits_max)
	{
		i = 0;
		while (units_sorted[i])
		{
			while ((*stack_a)->next != NULL)
			{
				if ((*stack_a)->data < 0)
				{
					if (i != ((temp * -1) % exp))
					{
						temp = (*stack_a)->data;
						temp = (((temp * -1) - i) / exp);
						tab[temp] = (*stack_a)->data;
					}
					else
						(*stack_a) = (*stack_a)->next;
				}
				else
				{
					if (i != (temp % exp))
					{
						temp = (*stack_a)->data;
						temp = ((temp - i) / exp);
						tab[temp] = (*stack_a)->data;
					}
					else
						(*stack_a) = (*stack_a)->next;
				}
				(*stack_a) = (*stack_a)->next;
			}
			i++;
		}
		nb_of_pass++;
		exp++;
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
