/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
*/
void	rotate_a(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->data;
	while (stack_a->next != NULL)
	{
		stack_a->data = stack_a->next->data;
		stack_a = stack_a->next;
	}
	stack_a->data = temp;
}

/*
Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
*/
void	rotate_b(t_stack *stack_b)
{
	int	temp;

	temp = stack_b->data;
	while (stack_b->next != NULL)
	{
		stack_b->data = stack_b->next->data;
		stack_b = stack_b->next;
	}
	stack_b->data = temp;
}

/*
ra et rb en même temps
*/
void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
