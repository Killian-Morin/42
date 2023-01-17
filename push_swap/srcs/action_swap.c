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
Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
ne sais pas si dois free le temp à la fin (pour le moment enleve)
*/
void	swap_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	temp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = temp;
	ft_putstr("sa\n");
}

/*
Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ne sais pas si dois free le temp à la fin (pour le moment enleve)
*/
void	swap_b(t_stack *stack_b)
{
	int	temp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	temp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = temp;
	ft_putstr("sb\n");
}

/*
sa et sb en même temps
*/
void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(*stack_a);
	swap_b(*stack_b);
}
