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
# include <limits.h>

typedef struct t_list
{
	int				data;
	struct t_list	*next;
}					t_stack;

/* push_swap.c */
int		main(int argc, char *argv[]);
void	push_swap(t_stack *stack_a, t_stack *stack_b, int nb_element);
t_stack	*fill_value_in_stack(int argc, char **argv);
int		stack_is_sorted(t_stack *stack);

/* sort_small_stack.c */
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b, int nb_element);
void	sort_three_element(t_stack *stack_a);
void	sort_four_element(t_stack *stack_a, t_stack *stack_b);
void	sort_five_element(t_stack *stack_a, t_stack *stack_b);

/* sort_big_stack.c */
void	sort_big_stack(int nb_element);

/* correct_input.c */
int		int_only(char **argv);
int		check_for_duplicate(int argc, char **argv);
int		check_correct_value(int argc, char **argv);

/* stack_manipulation.c */
t_stack	*add_first_node(int value);
void	add_node_bottom(t_stack *stack, int value);
t_stack	*find_last_node(t_stack *stack);
t_stack	*find_previous_last_node(t_stack *stack);

/* action_push.c */
void	push_a(t_stack **stack_dest, t_stack **stack_src);
void	push_b(t_stack **stack_dest, t_stack **stack_src);

/* action_reverse_rotate.c */
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);

/* action_rotate.c */
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);

/* action_swap.c */
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);

/* utils.c */
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

long int	ft_atoi(char *str);

#endif
