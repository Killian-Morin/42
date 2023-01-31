/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:11:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 10:11:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*fill_value_in_stack(int argc, char **argv)
{
	int			i;
	long int	value;
	t_stack		*stack_a;

	stack_a = NULL;
	i = 1;
	value = 0;
	while (i != argc)
	{
		value = ft_atoi(argv[i]);
		if (i == 1)
			stack_a = add_first_node((int)value);
		else
			add_node_bottom(stack_a, value);
		i++;
	}
	return (stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int nb_elem)
{
	if (stack_is_sorted(*stack_a) == 0)
		return ;
	else if (nb_elem == 2)
		swap_a(*stack_a);
	else if (nb_elem > 2 && nb_elem <= 5)
		sort_small_stack(stack_a, stack_b, nb_elem);
	else
		sort_big_stack(stack_a, stack_b, nb_elem);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		exit (EXIT_FAILURE);
	if (check_correct_value(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack_a = fill_value_in_stack(argc, argv);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b, (argc - 1));
	// free(&stack_a);
	// free(&stack_b);
	while (argc != 1)
	{
		printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
		argc--;
	}
	return (0);
}
