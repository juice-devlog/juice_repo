#include "push_swap.h"

int	is_a_sorted(t_stack *a, int count)
{
	if (count <= 1)
		return (1);
	else if (count == 2 && a->top->data < a->top->next->data)
		return (1);
	else if (count == 3 && (a->top->data < a->top->next->data
			&& a->top->next->data < a->top->next->next->data))
		return (1);
	return (0);
}

int	is_b_sorted(t_stack *b, int count)
{
	if (count <= 1)
		return (1);
	else if (count == 2 && b->top->data > b->top->next->data)
		return (1);
	else if (count == 3 && (b->top->data > b->top->next->data
			&& b->top->next->data > b->top->next->next->data))
		return (1);
	return (0);
}

void sort_a_under_three(t_stack *a, int count)
{
	int	n1;
	int	n2;
	int	n3;

	while (!(is_a_sorted(a, count)))
	{
		n1 = a->top->data;
		n2 = a->top->next->data;
		if (count == 3)
			n3 = a->top->next->next->data;
		if (count == 2 || (n1 > n2 && n1 > n3) || (n3 > n1 && n3 > n2))
			sa(a);
		else if ((n2 > n1 && n2 > n3))
		{
			ra(a);
			sa(a);
			rra(a);
		}
	}
}

void sort_b_under_three(t_stack *b, int count)
{
	int	n1;
	int	n2;
	int	n3;

	while (!(is_b_sorted(b, count)))
	{
		n1 = b->top->data;
		n2 = b->top->next->data;
		if (count == 3)
			n3 = b->top->next->next->data;
		if (count == 2 || (n1 < n2 && n1 < n3) || (n3 < n1 && n3 < n2))
			sb(b);
		else if ((n2 < n1 && n2 < n3))
		{
			rb(b);
			sb(b);
			rrb(b);
		}
	}
}