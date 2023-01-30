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

t_stack	*copy_list(t_stack **stack)
{
    t_stack *result;
	
	result = NULL;
	result->data = (*stack)->data;
	result->next = copy_list(stack);
    return (result);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int nb_elem)
{
	t_stack	*tmp;
	int		n;
	int		middle;
	int		size_chunk;
	int		start;
	int		end;
	int		i;

	tmp = copy_list(stack_a);
	printf("ici\n");
	n = 1;
	while ((nb_elem / n) > 20)
	{
		n--;
	}
	middle = nb_elem / 2;
	size_chunk = nb_elem / n;
	start = 0;
	end = size_chunk;
	while ((*stack_a))
	{
		i = start;
		while (i != size_chunk)
		{
			if ((*stack_a)->data >= start && (*stack_a)->data <= end)
				push_b(stack_b, stack_a);
			if ((*stack_b)->data < middle)
				rotate_b(stack_b);
			i++;
		}
		start += size_chunk;
		size_chunk += size_chunk;
	}
}

/*
void	counting_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	t_stack	*tmp;

	max = find_max_data(*stack_a);
	while (tmp->next != NULL)
	{
		tmp->data = (*stack_a)->data;
		(*stack_a) = (*stack_a)->next;
		tmp = tmp->next;
	}
}

void radix_sort (t_stack **stack_a)
{
   t_stack **tmp_double;
   t_stack *tmp_simple;
   int	max;
   int	NOP;
   int	pass;
   int	i;
   int	j;
   int	r;
   int	divisor;

   max = find_max_data(*stack_a);
   NOP = 0;
   while (max > 0)
   {
	  NOP++;
      max /= 10;
   }
   pass = 0;
   divisor = 1;
   while (pass < NOP)
   {
	  i = 0;
      while (i < 10)
	  {
        tmp_simple->data = 0;
		i++;
		tmp_simple = tmp_simple->next;
      }
      while (stack_a->next != NULL)
	  {
        r = ((*stack_a)->data / divisor) % 10;
        tmp_double->data = stack_a;
        tmp_simple->data += 1;
		stack_a = stack_a->next;
      }
      while (tmp_simple->next != NULL)
	  {
		j = 0;
        while (j < tmp_simple->data)
		{
           stack_a = tmp_double;
		   j++;
        }
		tmp_simple = tmp_simple->next;
      }
      divisor *= 10;
	  pass++;
   }
}

t_stack	*temp;

temp = (t_stack *)malloc(sizeof(t_stack));
if (!temp)
	return (NULL);
temp->data = (*stack)->data;
temp = copy_list(&(*stack)->next);

return (temp);
	*/
