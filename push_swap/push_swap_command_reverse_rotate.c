#include "./push_swap.h"

void	rra(t_stack *a)
{
	t_node *first;
	t_node *last;

	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	if (first == last)
		return;
	while (first->next != last)
		first = first->next;
	first->next = 0;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
	t_node *first;
	t_node *last;

	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	if (first == last)
		return;
	while (first->next && first->next != last)
		first = first->next;
	first->next = 0;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}