/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_second_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:50:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/10 09:50:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	t_stack	*temp;
	int		i;

	temp[0] = stack_a[0];
	i = 1;
	while (i != ft_lstsize(stack_a))
	{
		stack_a[i - 1] = stack_a[i];
		i++;
	}
	stack_a[i] = temp[0];
}

void	rotate_b(t_stack *stack_b)
{
	t_stack	*temp;
	int		i;

	temp[0] = stack_b[0];
	i = 1;
	while (i != ft_lstsize(stack_b))
	{
		stack_b[i - 1] = stack_b[i];
		i++;
	}
	stack_b[i] = temp[0];
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = ft_lstsize(stack_a);
	temp[0] = stack_a[i];
	while (i != 0)
	{
		stack_a[i - 1] = stack_a[i];
		i--;
	}
	stack_a[0] = temp[0];
}

void	reverse_rotate_b(t_stack *stack_b)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = ft_lstsize(stack_b);
	temp[0] = stack_b[i];
	while (i != 0)
	{
		stack_b[i - 1] = stack_b[i];
		i--;
	}
	stack_b[0] = temp[0];
}

void	reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
