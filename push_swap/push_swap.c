/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:11:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 10:11:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(t_stack *stack_a, int nb_element)
{
    if (nb_element <= 5)
        sort_small_stack(stack_a, nb_element);
    // else
    //     sort_big_stack(stack_a, nb_element);
}

int    main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    stack_a = NULL;
    i = 1;
    if (argc >= 2)
    {
        if (check_correct_value(argv) != 0)
        {
            stack_a = malloc(sizeof(stack_a) * (argc - 1));
            if (!stack_a)
                return (NULL);
            while (**argv)
            {
                stack_a[i] = *argv[i];
                i++;
            }
            push_swap(stack_a, i);
        }
        else
            ft_putstr_fd("Error\n", 1);
    }
    return (0);
}