/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:38:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:34:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		signal;

	min = NULL;
	signal = 0;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (!signal || head->data < min->data))
		{
			min = head;
			signal = 1;
		}
		head = head->next;
	}
	return (min);
}

void	organize_index_stack(t_stack **stack)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = get_next_min(stack);
	while (temp)
	{
		temp->index = index++;
		temp = get_next_min(stack);
	}
}

void	fill_value_in_stack(int argc, char **argv, t_stack **stack_a)
{
	int			i;
	char		**av;
	t_stack		*new;

	i = 0;
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		av = argv;
	}
	if (!av)
		ft_free_char_string(av);
	while (av[i])
	{
		new = ft_lstnew(ft_ascii_to_long_int(av[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	organize_index_stack(stack_a);
	if (argc == 2)
		ft_free_char_string(av);
}
