/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Intervertit les 2 premiers éléments au sommet de la stack passe en arg.
Ne fait rien s’il n’y en a qu’un ou aucun.

créer 2 var qui stock la data et l'index du 1er node;
attribue la data et l'index du 2eme node au 1er node;
attribue la data et l'index de temp au 2eme node correspondant au 1er node
*/
static void	swap(t_stack *stack)
{
	int	temp_data;
	int	temp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp_data = stack->data;
	temp_index = stack->index;
	stack->data = stack->next->data;
	stack->index = stack->next->index;
	stack->next->data = temp_data;
	stack->next->index = temp_index;
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

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
