/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Intervertit les 2 premiers éléments au sommet de la stack passe en arg.
Ne fait rien s’il n’y en a qu’un ou aucun.
ne sais pas si dois free le temp à la fin (pour le moment enleve)
*/
static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
}

void	swap_a(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

/*
sa et sb en même temps
*/
void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
