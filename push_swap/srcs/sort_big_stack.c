/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b, int nb_element)
{
	printf("en travail :) %d elements\n", nb_element);
	while ((*stack_a)->next != NULL)
	{
		printf("stack_a : %d\n", (*stack_a)->data);
		(*stack_a) = (*stack_a)->next;
	}
}
