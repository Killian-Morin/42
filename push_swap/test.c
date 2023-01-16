#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
ancien push
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*new_node;
	t_stack	*head;

	if (!stack_b)
		return ;
	new_node = NULL;
	head = find_first_node(stack_a);
	new_node->data = stack_b->data;
	new_node->next = head;
	head = new_node;
}

autre ancien push
new_node = stack_a->next;
stack_a->next = stack_b;
stack_b = stack_a;
stack_a = new_node;
new_node = NULL;
*/