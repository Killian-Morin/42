/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*partition(t_stack *first, t_stack *last)
{
	t_stack	*pivot;
	t_stack	*front;
	int		temp;

	pivot = first;
	front = first;
	temp = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)
			rotate_a(&first);
	}
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return (pivot);
}

void	quick_sort(t_stack *first, t_stack *last)
{
	t_stack	*pivot;

	if (first == last)
		return ;
	pivot = partition(first, last);
	if (pivot != NULL && pivot->next != NULL)
		quick_sort(pivot->next, last);
	if (pivot != NULL && first != pivot)
		quick_sort(first, pivot);
}
