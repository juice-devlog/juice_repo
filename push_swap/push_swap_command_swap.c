#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node *first;
	t_node *second;

	first = a->top;
	second = a->top->next;
	if (!first || !second)
		return ;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

void	sb(t_stack *b)
{
	t_node *first;
	t_node *second;

	first = b->top;
	second = b->top->next;
	if (!first || !second)
		return ;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}