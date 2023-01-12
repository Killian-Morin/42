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

#include "push_swap.h"

/*
s1 est la stack dt le 1er node est deplace vers s2 / le head doit changer pour pointer vers l'ancien 2nd node
s2 est la stack qui recoit le node deplace / le head doit etre update pour pointer vers le new_node, faire les autres changements qui s'impose
*/
void	push(t_stack *stack_deplace, t_stack *stack_recevant)
{
	if (!*stack_deplace)
		break ;
	else
	{
		/*
		del/free stack_recevant[0];
		copie le 1er node de la stack_deplace et le mettre en 1ere position sur la stack_recevant
		del stack_b[0] et monter tous ses elements de 1
		*/
	}
}