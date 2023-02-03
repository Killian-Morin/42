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
Prend le premier élément au sommet de src et le met sur dest.
Ne fait rien si src est vide.
stack_a est la src
stack_b est la dest

creer une var new_node qui contient le 2eme node de la src;
fait pointer le 1er node de la src vers la dest;
attribue le 1er node de la src au 1er node de la dest;
*/
static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*new_node;

	if (*stack_src == NULL)
		return ;
	new_node = (*stack_src)->next;//prend le 2eme node de src (qui sera le 1er apres la manip)
	(*stack_src)->next = *stack_dest;//fait pointer ce node de src vers la head de dest
	*stack_dest = *stack_src;//la head de dest prend le 1er node de la src
	*stack_src = new_node;//le head de src prend le 2eme node de la src
}

static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*new_node;

	if (*stack_src == NULL)
		return ;
	if (*stack_dest == NULL)
	{
		new_node = (*stack_src);
		new_node->next = NULL;
		*stack_src = new_node;
	}
	else
	{
		new_node = (*stack_src);
		new_node->next = (*stack_dest);
		(*stack_dest) = new_node;
		(*stack_src) = (*stack_src)->next;
	}
}

static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_list	*tmp;
	t_list	*head_dest;
	t_list	*head_src;

	if (*stack_src == NULL)
		return ;
	head_dest = *stack_dest;//prend le 1er node de dest
	head_src = *stack_src;//prend le 1er node de src
	tmp = head_src;//prend le 1er node de src
	head_src = head_src->next;//pour que le node head pointe vers le 2eme node
	*stack_src = head_src;//pour que le 1er node soit l'ancien 2eme node
	if (!head_dest)//si dest est vide
	{
		head_dest = tmp;//le head de dest prend tmp/1er node de src
		head_to->next = NULL;//le head de dest pointe vers NULL vu que c'est le seul element de la stack
		*stack_dest = head_dest;//le 1er node de dest soit le head de dest
	}
	else//si il y a des elements ds dest
	{
		tmp->next = head_dest;//pour que tmp pointe vers le 1er node de dest qui sera dc le 2eme node
		*stack_dest = tmp;//le 1er node de dest est le tmp
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
