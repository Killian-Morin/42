/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack *stack_a, int nb_element)
{
	if (nb_element == 2)
	{
		//ex: 1 2
		if (stack_a[0] < stack_a[1])
			ft_printf("\n");
		//ex: 2 1
		else
			ft_printf("%s\n", "sa");
	}
	if (nb_element == 3)
		sort_three_element(stack_a);
	if (nb_element == 4)
		sort_four_element(stack_a);
}

void	sort_three_element(t_stack *stack_a)
{
	//stack_a[0] est le min: 1 2 3 ou 1 3 2
	if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2])
	{
		//1 2 3, déjà croissants
		if (stack_a[1] < stack_a[2])
			ft_printf("\n");
		//1 3 2, monter le max puis le mettre dernier
		else if (stack_a[1])
			ft_printf("%s\n%s\n", "sa", "ra");
	}
	//stack_a[1] est le min: 2 1 3 ou 3 1 2
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
	{
		//2 1 3, le max est le der dc intervertit l'element 0 et l'element 1
		if (stack_a[0] < stack_a[2])
			ft_printf("%s\n", "sa");
		//3 1 2, le max est l'element 0 dc on le met à la fin
		else
			ft_printf("%s\n", "ra");
	}
	//stack_a[2] est le min: 2 3 1 ou 3 2 1
	else if (stack_a[0] > stack_a[2] && stack_a[1] > stack_a[2])
	{
		//2 3 1, monter le min à la 1ere place
		if (stack_a[0] < stack_a[1])
			ft_printf("%s\n", "rra");
		//3 2 1, intervertir l'element 0 avec l'element 1 puis monter le min à la 1ere place
		else
			ft_printf("%s\n%s\n", "sa", "rra");
	}
}

void	sort_four_element(stack_a)
{
	ft_printf("%s\n", "pb");//push stack_a[0] sur stack_b[0]
	//le faire, deplacer l'element
	sort_three_element(stack_a);
	ft_printf("%s\n", "pa");//push stack_b[0] sur stack_a[0]
	//le faire, deplacer l'element

	//stack_a[0] < stack_a[1] qui est deja le min de la stack trie
	if (stack_a[0] < stack_a[1])
		ft_printf("%s\n", "rien faire");//pas besoin d'actions
	//stack_a[1] < stack_a[0] < stack_a[2]
	else if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
	{
		ft_printf("%s\n", "sa");
		//le faire, deplacer l'element
	}
	//stack_a[2] < stack_a[0] < stack_a[3]
	else if (stack_a[2] < stack_a[0] && stack_a[0] stack_a[3])
	{
		ft_printf("%s\n%s\n%s\n%s\n", "rra", "sa", "ra", "ra");
		//le faire, deplacer l'element
	}
	//stack_a[3] < stack_a[0]
	else if (stack_a[3] < stack_a[0])
	{
		ft_printf("%s\n", "ra");
		//le faire, deplacer l'element
	}
}