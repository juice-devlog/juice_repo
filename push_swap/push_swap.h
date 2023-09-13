#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
#include <unistd.h>
# include <stdlib.h>

typedef struct s_node{
	int data;
	struct s_node *next;
} t_node;

typedef struct s_stack{
	t_node *top;
	t_node *bottom;
} t_stack;

void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void a_to_b(t_stack *a, t_stack *b, int count);
void sort_a_under_three(t_stack *a);
void quick_sort(int *arr, int start, int end);
int get_small_pivot(t_stack *s, int count);
int get_large_pivot(t_stack *s, int count);

#endif