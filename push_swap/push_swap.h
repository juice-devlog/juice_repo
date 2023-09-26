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

typedef struct s_info{
	int	small_pivot;
	int	large_pivot;
	int	p_cnt;
	int	ra_cnt;
	int	rb_cnt;
}	t_info;

// push_swap_free_error.c
void	display_error(int *arr, char *num);
void	free_stack(t_stack *a, t_stack *b);

// push_swap_parse.c
int		count_numbers(char *s);
char	*make_num(int *arr, char *s, int len);
int		check_atoi(int *arr, char *num);
void	fill_arr(char *s, int *arr, int *arr_idx);
int		*parse_arg(char **argv, int *num_cnt);

// push_swap_init.c
t_node	*create_new_node(int num);
t_stack	*init_stack_a(int *arr, int num_cnt);
t_stack	*init_stack_b(void);
t_info	*init_info(void);

// push_swap_command_push.c
void	push(t_stack *s1, t_stack *s2);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// push_swap_command_swap.c
void	swap(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// push_swap_command_rotate.c
void	rotate(t_stack *s);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// push_swap_command_reverse_rotate.c
void	reverse_rotate(t_stack *s);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// push_swap_exec.c
void	start_sorting(t_stack *a, t_stack *b, int count);
void	a_to_b(t_stack *a, t_stack *b, int count);
void	b_to_a(t_stack *a, t_stack *b, int count);

// push_swap_exec_while.c
void	start_sorting_while(t_stack *a, t_stack *b, int *count, t_info *info);
void	b_to_a_while(t_stack *a, t_stack *b, int *count, t_info *info);
void	a_to_b_while(t_stack *a, t_stack *b, int *count, t_info *info);
void	merge_rra_rrb_count(t_stack *a, t_stack *b, int ra_count, int rb_count);

// push_swap_sort.c
int		is_sorted(t_stack *s, char stack, int count);
void	sort_a_under_three(t_stack *a, int count);
void	sort_b_under_three(t_stack *b, int count);
void	sort_a_only_three(t_stack *a);
void	sort_b_only_three(t_stack *b);

// push_swap_get_pivot.c
void	ft_swap(int *a, int *b);
void	quick_sort(int *arr, int start, int end);
void	get_pivot(t_stack *s, int count, t_info *info);

void	print_ab(t_stack *a, t_stack *b);

#endif