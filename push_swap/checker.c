/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:21 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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

void	checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	while (*line)
	{
		if (*line == "sa")
			swap_a(stack_a);
		if (*line == "sb")
			swap_b(stack_b);
		if (*line == "ss")
			swap_ss(stack_a, stack_b);
		if (*line == "ra")
			rotate_a(stack_a);
		if (*line == "rb")
			rotate_b(stack_b);
		if (*line == "rr")
			rotate_r(stack_a, stack_b);
		if (*line == "rra")
			reverse_rotate_a(stack_a);
		if (*line == "rrb")
			reverse_rotate_b(stack_b);
		if (*line == "rrr")
			reverse_rotate_r(stack_a, stack_b);
		if (*line == "pa")
			push_a(stack_a, stack_b);
		if (*line == "pb")
			push_b(stack_b, stack_a);
		line++;
	}
}

int	main(int argc, char **argv)
{
	char		*line;
	t_stack		**stack_a;
	t_stack		**stack_b;
	int			i;

	if (check_correct_value(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_value_in_stack(argc, argv, stack_a);
	i = 0;
	while (get_next_line(0))
	{
		line[i] = get_next_line(0);
		i++;
	}
	checker(stack_a, stack_b, line);
	if (stack_is_sorted(*stack_a) == 0 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
