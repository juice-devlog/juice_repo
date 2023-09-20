#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node *first;
	t_node *second;

	first = a->top;
	second = a->top->next;
	if (first && second)
	{
		first->next = second->next;
		second->next = first;
		a->top = second;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node *first;
	t_node *second;

	first = b->top;
	second = b->top->next;
	if (first && second)
	{
		first->next = second->next;
		second->next = first;
		b->top = second;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	t_node *first;
	t_node *second;

	first = a->top;
	second = a->top->next;
	if (first && second)
	{
		first->next = second->next;
		second->next = first;
		a->top = second;
	}
	first = b->top;
	second = b->top->next;
	if (first && second)
	{
		first->next = second->next;
		second->next = first;
		b->top = second;
	}
	write(1, "ss\n", 3);
}