/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/12 13:12:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.

stack_a est la dest
stack_b est la src
*/
void	push_a(t_stack *stack_dest, t_stack *stack_src)
{
	t_stack	*new_node;

	if (!stack_src)
		return ;
	new_node = stack_src->next;
	stack_src->next = stack_dest;
	stack_dest = stack_src;
	stack_src = new_node;
}

/*
Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.

stack_a est la src
stack_b est la dest

creer le new_node
le new_node prend en data, la data de stack_src soit new_node = stack_src->data
le new_node prend en next, NULL si stack_dest etait vide avant, sinon pointe vers stack_dest->next pour avoir le pointeur du node precedement premier
a voir si le if est vraiment obligatoire pour les prochains essais enlever
le head de stack_dest pointe vers new_node soit head_stack_src = new_node
le head de stack_src pointe vers l'ancien 2eme node soit head_stack_src = stack_src->next
*/
void	push_b(t_stack *stack_dest, t_stack *stack_src)
{
	t_stack	*new_node;

	if (!stack_src)
		return ;
	new_node = stack_src->next;
	stack_src->next = stack_dest;
	stack_dest = stack_src;
	stack_src = new_node;
	// t_stack	*new_node;
	// t_stack	*head_stack_src;

	// if (!stack_src)
	// 	return ;
	// new_node = NULL;
	// head_stack_src = NULL;
	// new_node->data = stack_src->data;
	// if (!stack_dest)
	// 	new_node->next = stack_dest;
	// else
	// 	new_node->next = stack_dest->next;
	// stack_dest = new_node;
	// head_stack_src->next = stack_src->next;
}
