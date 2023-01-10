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

typedef	struct	t_list
{
	int				*value;
	struct s_list	*next;
}					t_stack;

//ds push_swap.c
int	main(int argc, char *argv[]);
void	push_swap(t_stack *stack_a, int nb_element);

//ds sort_small_stack.c
void	sort_small_stack(t_stack *stack_a, int nb_element);
void	sort_three_element(t_stack *stack_a);

//ds correct_input.c
int		check_for_duplicate(char **argv);
int		check_correct_value(char **argv);

//ds action_first_part.c
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
//ds action_second_part.c
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
