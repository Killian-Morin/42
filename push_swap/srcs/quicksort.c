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

t_stack	*get_median(t_stack *head, t_stack *tail)
{
	t_stack	*median;
	int		i;

	i = 0;
	if ((ft_lstsize(head) % 2) == 1) //impair
	{
		while (i != (ft_lstsize(head) % 2 + 0.5))
		{
			head = head->next;
			i++;
		}
		median = head;
	}
	else if ((ft_lstsize(head) % 2) == 0) //pair
	{
		while (i != (ft_lstsize(head) % 2))
		{
			head = head->next;
			i++;
		}
		median = head;
	}
	return (median);
}

t_stack	*partition(t_stack *head, t_stack *tail, t_stack **stack_b)
{
	t_stack	*pivot;
	t_stack	*curr;
	t_stack	*prev;

	pivot = get_median(head, tail);//prend la mediane
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
/* temp pour stockage voir si utile */
Node* partition(Node* head,  Node* end, Node** newHead, Node** newEnd)
{
    Node* pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // The first node that will be having value less than the
            // pivot node value will become the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else // If the value of the cur node is greater than that of the pivot
        {
            // We will move the cur node to next of tail, and will update tail
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    // If the data of the pivot node is smallest in the
    // current list, then we will make pivot as the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    // newEnd will be updated to the current last node
    (*newEnd) = tail;
    // Finally, we will return the pivot node
    return pivot;
}
