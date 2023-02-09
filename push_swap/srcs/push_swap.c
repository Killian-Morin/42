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

void	fill_value_in_stack(int argc, char **argv, t_stack **stack)
{
	int			i;
	char		**av;
	t_stack		*new;

	i = 0;
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		av = argv;
	}
	while (av[i])
	{
		new = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free(av);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_is_sorted(*stack_a) == 0)
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else if (ft_lstsize(*stack_a) == 2)
		swap_a(*stack_a);
	else if (ft_lstsize(*stack_a) > 2 && ft_lstsize(*stack_a) <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		// quick_sort((*stack_a), find_last_node(*stack_a));
		sort_big_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	if (check_correct_value(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_value_in_stack(argc, argv, stack_a);
	push_swap(stack_a, stack_b);
	while ((*stack_a))
	{
		printf("%d\n", (*stack_a)->data);
		(*stack_a) = (*stack_a)->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
