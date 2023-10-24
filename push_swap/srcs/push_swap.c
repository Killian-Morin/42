/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:11:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		else
			i++;
	}
	return (0);
}

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

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_is_sorted(*stack_a) == 0)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		swap_a(*stack_a);
	else if (ft_lstsize(*stack_a) > 2 && ft_lstsize(*stack_a) <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2 || (argc == 2 && ft_strchr(argv[1], ' ') == 0))
		return (-1);
	if (check_correct_value(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a)
		return (-1);
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_b)
		return (-1);
	*stack_a = NULL;
	*stack_b = NULL;
	fill_value_in_stack(argc, argv, stack_a);
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
