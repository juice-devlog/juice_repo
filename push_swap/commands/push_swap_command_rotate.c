#include "./push_swap.h"

void	ra(t_stack *a)
{
	t_node *first;
	t_node *last;

	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	if (first != last)
	{
		last->next = first;
		a->top = first->next;
		first->next = 0;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node *first;
	t_node *last;

	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	if (first != last)
	{
		last->next = first;
		b->top = first->next;
		first->next = 0;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node *first;
	t_node *last;

	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	if (first != last)
	{
		last->next = first;
		a->top = first->next;
		first->next = 0;
	}
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	if (first != last)
	{
		last->next = first;
		b->top = first->next;
		first->next = 0;
	}
	write(1, "rr\n", 3);
}