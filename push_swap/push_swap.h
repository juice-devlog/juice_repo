/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:17:41 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/14 19:17:41 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack{
	t_node	*top;
}	t_stack;

void	display_error(void);
void	free_on_parse_error(int *arr, char **numbers);
int		check_atoi(int *arr, char **numbers, int idx);
void	init_array(int *arr, char **argv);
int		*parse_arg(int argc, char **argv, int *num_cnt);
int		count_word(char const *s, char c);
char	*put_word(char const *s, char c);
void	free2(char **str);
char	**ft_split(char const *s, char c);
t_node	*create_new_node(int num);
t_stack	*init_stack_a(int *arr, int num_cnt);
t_stack	*init_stack_b(void);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	start_sorting(t_stack *a, t_stack *b, int count);
void	a_to_b(t_stack *a, t_stack *b, int count);
void	b_to_a(t_stack *a, t_stack *b, int count);
void start_sorting_while(t_stack *a, t_stack *b, int *count, int *pivot_small_large, int *count_pb_ra_rb);
void b_to_a_while(t_stack *a, t_stack *b, int *count, int *pivot_small_large, int *count_pa_ra_rb);
void a_to_b_while(t_stack *a, t_stack *b, int *count, int *pivot_small_large, int *count_pb_ra_rb);
void merge_rra_rrb_count(t_stack *a, t_stack *b, int ra_count, int rb_count);
int is_sorted(t_stack *s, char stack, int count);
void	sort_a_under_three(t_stack *a, int count);
void	sort_b_under_three(t_stack *b, int count);
void	quick_sort(int *arr, int start, int end);
void get_pivot(t_stack *s, int count, int *pivot_small_large);
void sort_a_only_three(t_stack *a);
void	sort_b_only_three(t_stack *b);
int check_sorted(t_stack *a);

#endif