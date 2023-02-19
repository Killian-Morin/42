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

int	get_median(t_stack *head)
{
	int	median;
	int	i;

	i = 0;
	if ((ft_lstsize(head) % 2) == 1) //impair
	{
		while (i != (ft_lstsize(head) % 2 + 0.5))
		{
			head = head->next;
			i++;
		}
		median = head->data;
	}
	else if ((ft_lstsize(head) % 2) == 0) //pair
	{
		while (i != (ft_lstsize(head) % 2))
		{
			head = head->next;
			i++;
		}
		median = head->data;
	}
	return (median);
}

t_stack	*partition(t_stack *head, t_stack *tail, t_stack **stack_b)
{
	int		pivot;
	t_stack	*curr;
	t_stack	*prev;

	pivot = get_median(head);//prend la mediane
	curr = head->next;
	prev = head;
	while (curr != tail->next)
	{
		if (pivot > curr->data)
		{
			swap(prev->next->data, curr->data);//swap les 2 elements precise ds la liste (mais c'est pas les 2 premiers comme l'instruction)
			prev = prev->next;
		}
		curr = curr->next;
	}
	swap(prev->data, pivot);//swap le dernier element avec l'avant dernier
	return (prev);
}

void	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*pivot;

	head = *stack_a;
	if (head == NULL || head->next == NULL)
		return ;
	tail = find_last_node(head);
	if (tail == NULL || head == tail)
		return ;
	pivot = partition(head, tail, stack_b);
	solvesort(head, pivot);//1er appel pour faire de head à pivot
	solvesort(pivot->next, tail);//2eme appel pour faire le suite de la stack i.e. le node suivant le pivot jusqu'a la fin
}
