#include "push_swap.h"

void sort_a_only_three(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	while (!(is_sorted(a, 'a', 3)))
	{
				//exit(1);
		n1 = a->top->data;
		n2 = a->top->next->data;
		n3 = a->top->next->next->data;
		if ((n2 > n1 && n2 > n3 && n1 < n3) || (n3 > n1 && n3 > n2))
			sa(a);
		else if ((n1 > n2 && n1 > n3))
			ra(a);
		else if (n2 > n1 && n2 > n3 && n1 > n3)
			rra(a);
	}
}

void	sort_b_only_three(t_stack *b)
{
	int	n1;
	int	n2;
	int	n3;

	while (!(is_sorted(b, 'b', 3)))
	{
		//exit(1);

		n1 = b->top->data;
		n2 = b->top->next->data;
		n3 = b->top->next->next->data;
		if ((n1 > n2 && n1 > n3) || (n2 > n1 && n2 > n3 && n1 > n3)
			|| (n3 > n1 && n3 > n2 && n2 > n1))
			sb(b);
		else if ((n2 > n1 && n2 > n3))
			rb(b);
		else if (n3 > n1 && n3 > n2)
			rrb(b);
	}
}

int check_sorted(t_stack *a)
{
	t_node *cur;

	cur = a->top;
	while (cur->next)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	is_sorted(t_stack *s, char stack, int count)
{
	if (count <= 1)
		return (1);
	if (stack == 'a')
	{
		if (count == 2 && s->top->data < s->top->next->data)
			return (1);
		else if (count == 3 && (s->top->data < s->top->next->data
				&& s->top->next->data < s->top->next->next->data))
			return (1);
	}
	else if (stack == 'b')
	{
		if (count == 2 && s->top->data > s->top->next->data)
			return (1);
		else if (count == 3 && (s->top->data > s->top->next->data
				&& s->top->next->data > s->top->next->next->data))
			return (1);
	}
	return (0);
}

void sort_a_under_three(t_stack *a, int count)
{
	int	n1;
	int	n2;
	int	n3;

	if (count == 3 && !a->top->next->next->next)
		sort_a_only_three(a);
	while (!(is_sorted(a, 'a', count)))
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

	if (count == 3 && !b->top->next->next->next)
		sort_b_only_three(b);
	while (!(is_sorted(b, 'b', count)))
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
