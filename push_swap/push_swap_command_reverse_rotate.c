#include "./push_swap.h"

void	rra(t_stack *a)
{
	t_node *last;
	t_node *new_bottom;

	last = a->bottom;
	new_bottom = a->top;
	while (new_bottom->next != last)
		new_bottom = new_bottom->next;
	new_bottom->next = 0;
	a->bottom = new_bottom;
	last->next = a->top;
	a->top = last;
	return;
}

void rrb(t_stack *b)
{
	t_node *last;
	t_node *new_bottom;

	last = b->bottom;
	new_bottom = b->top;
	while (new_bottom->next != last)
		new_bottom = new_bottom->next;
	new_bottom->next = 0;
	b->bottom = new_bottom;
	last->next = b->top;
	b->top = last;
	return;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}