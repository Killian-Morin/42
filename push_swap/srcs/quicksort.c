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

t_stack	*partition(t_stack *head, t_stack *tail)
{
	t_stack	*pivot;
	t_stack	*current;
	t_stack	*prev;

	pivot = head;
	prev = head;
	current = head->next;
	while (current != tail->next)//soit NULL
	{
		if (pivot->data > current->data)
		{
			rotate_a(head);
		}
		current = currrent->next;
	}
	return (prev);
}

void	solvesort(t_stack *head, t_stack *tail)
{
	t_stack	*pivot;

	if (head == NULL || tail == NULL || head == tail)
		return ;
	pivot = partition(head, tail);
	solvesort(head, pivot);
	solvesort(pivot->next, tail);
}

void	quicksort(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack_a;
	if (head == NULL || head->next == NULL)
		return ;
	tail = find_last_node(head);
	solveSort(head, tail);
}
t_stack	*find_last_node(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack *partition(t_stack *head, t_stack *tail)
{
    t_stack *pivot;
    t_stack *curr;
    t_stack *prev;

    pivot = head;
    curr = head->next;
    prev = head;
    while (curr != tail->next)
    {
        if (pivot->data > curr->data)
        {
            swap(prev->next->data, curr->data);//swap les 2 elements precise ds la liste (mais c'est pas les 2 premiers comme l'instruction)
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(prev->data, pivot->data);//swap le dernier element avec l'avant dernier
    return (prev);
}

void    solveSort(t_stack *head, t_stack *tail)
{
    t_stack *pivot;

    if (head == NULL || tail == NULL || head == tail)
        return ;
    pivot = partition(head, tail);
    solveSort(head, pivot);//trie les elements plus petit que pivot
    solveSort(pivot->next, tail);//trie les elements plus grd que pivot
}

void    quicksort(t_stack **stack)
{
    t_stack *head;
    t_stack *tail;
    
    head = *stack;
    if (head == NULL || head->next == NULL)
        return ;
    tail = find_last_node(*head);
    solveSort(head, tail);
}
