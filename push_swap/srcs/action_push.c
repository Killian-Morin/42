/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Prend le premier élément au sommet de src et le met sur dest.
Ne fait rien si src est vide.

creer une var head_dest qui prend le 1er node de dest,
creer une var head_src qui prend le 1er node de src,
creer une var tmp qui prend head_src soit le 1er node de src;
attribue le 2eme node de src a head_src,
attribue head_src comme 1er node de stack_src;
si la dest est vide,
	alors head_dest prend comme valeur tmp/1er node de src,
	head_dest pointe vers NULL comme pas d'autre element ds la stack,
	attribue head_dest comme 1er node de stack_dest;
si il y a des elements ds dest,
	alors fait pointer tmp vers head_dest,
	attribue tmp comme 1er node de stack_dest;
*/
static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*tmp;
	t_stack	*head_dest;
	t_stack	*head_src;

	if (*stack_src == NULL)
		return ;
	head_dest = *stack_dest;
	head_src = *stack_src;
	tmp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dest)
	{
		head_dest = tmp;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
	else
	{
		tmp->next = head_dest;
		*stack_dest = tmp;
	}
}

/*
stack_a est la dest
stack_b est la src
*/
void	push_a(t_stack **stack_dest, t_stack **stack_src)
{
	push(stack_dest, stack_src);
	ft_putstr("pa\n");
}

/*
stack_a est la src
stack_b est la dest
*/
void	push_b(t_stack **stack_dest, t_stack **stack_src)
{
	push(stack_dest, stack_src);
	ft_putstr("pb\n");
}
