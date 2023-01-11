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

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b, int nb_element)
{
	if (nb_element <= 5)
		sort_small_stack(stack_a, stack_b, nb_element);
    // else
	// 	sort_big_stack(stack_a, nb_element);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		i;

// 	stack_a = NULL;
// 	i = 1;
// 	if (argc >= 2)
// 	{
// 		if (check_correct_value(argv) != 0)
// 		{
// 			stack_a = malloc(sizeof(stack_a) * (argc - 1));
// 			if (!stack_a)
// 				return (0);
// 			while (**argv)
// 			{
// 				stack_a[i] = *argv[i];
// 				i++;
// 			}
// 			push_swap(stack_a, i);
// 		}
// 		else
// 			ft_putstr_fd("Error\n", 1);
// 	}
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	if (check_correct_value(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 1;
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack) * (argc - 1));
	if (!stack_a)
		exit (1);
	while (i != argc)
	{
		stack_a->value[j] = *argv[i];
		i++;
		j++;
	}
}
