/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:35:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:35:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}					t_stack;

/* push_swap.c */
int			main(int argc, char **argv);
void		push_swap(t_stack **stack_a, t_stack **stack_b);
int			stack_is_sorted(t_stack *stack);
char	*ft_strchr(const char *str, int c);

/* correct_input.c */
int			int_only(char **argv);
int			check_for_duplicate(char **argv);
int			check_correct_value(int argc, char **argv);
int			ft_strcmp(char *s1, char *s2);

/* init_stack.c */
void		fill_value_in_stack(int argc, char **argv, t_stack **stack_a);
t_stack		*get_next_min(t_stack **stack);
void		organize_index_stack(t_stack **stack);

/* sort_small_stack.c */
void		sort_small_stack(t_stack **stack_a, t_stack **stack_b);
void		sort_three_element(t_stack **stack_a);
void		sort_four_element(t_stack **stack_a, t_stack **stack_b);
void		sort_five_element(t_stack **stack_a, t_stack **stack_b);

/* sort_big_stack.c */
void		radix_sort(t_stack **stack_a, t_stack **stack_b);
int			get_max_bits(t_stack **stack);

/* action_push.c */
void		push_a(t_stack **stack_dest, t_stack **stack_src);
void		push_b(t_stack **stack_dest, t_stack **stack_src);

/* action_reverse_rotate.c */
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);

/* action_rotate.c */
void		rotate_a(t_stack **stack);
void		rotate_b(t_stack **stack);
void		rotate_r(t_stack **stack_a, t_stack **stack_b);

/* action_swap.c */
void		swap_a(t_stack *stack_a);
void		swap_b(t_stack *stack_b);
void		swap_ss(t_stack *stack_a, t_stack *stack_b);

/* utils_stack.c */
t_stack		*ft_lstnew(int value);
void		ft_lstadd_back(t_stack **stack, t_stack *node);
t_stack		*find_last_node(t_stack *stack);
t_stack		*find_previous_last_node(t_stack *stack);
int			ft_lstsize(t_stack *lst);

/* utils.c */
void		ft_putchar(char c);
void		ft_putstr(char *str);
long int	ft_ascii_to_long_int(char *str);
void		ft_free_char_string(char **str);
void		free_stack(t_stack **stack);

/* ft_split.c */
int			ft_countmot(char *src, char c);
int			*ft_cara_par_str(char *src, char c, int nbmot);
char		**ft_free_split(char **bigstr, int i, int *len);
char		**ft_fill_tab(char *src, char c, char **bigstr, int *len);
char		**ft_split(char const *s, char c);

#endif
