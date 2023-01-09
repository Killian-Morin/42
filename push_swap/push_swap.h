/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:35:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/05 11:36:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct s_stack
{
    int    *value;
    struct s_stack *next;
}   t_stack;

//ds push_swap.c
void    push_swap(int *stack_a, int nb_element);

//ds sort_small_stack.c
void    sort_small_stack(int *stack_a, int nb_element);
void	sort_three_element(t_stack *stack_a);

#endif