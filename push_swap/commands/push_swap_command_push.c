#include "./push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node *top_b;

	top_b = b->top;
	b->top = top_b->next;
	top_b->next = a->top;
	a->top = top_b;
	write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
	t_node *top_a;

	top_a = a->top;
	a->top = top_a->next;
	top_a->next = b->top;
	b->top = top_a;
	write(1, "pb\n", 3);
}