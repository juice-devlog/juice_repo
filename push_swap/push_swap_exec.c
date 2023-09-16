#include "./push_swap.h"

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int 	small_pivot;
	int 	large_pivot;
	int 	ra_count;
	int 	rb_count;
	int 	pa_count;

	if (count <= 3)
	{
		sort_b_under_three(b, count);
		while (count--)
			pa(a, b);
		return ;
	}
	small_pivot = get_small_pivot(b, count);
	large_pivot = get_large_pivot(b, count);
	pa_count = 0;
	rb_count = 0;
	ra_count = 0;
	while (count--)
	{
		if (b->top->data >= small_pivot)
		{
			pa(a, b);
			pa_count++;
			if (a->top->data <= large_pivot)
			{
				ra(a);
				ra_count++;
			}
		}
		else
		{
			rb(b);
			rb_count++;
		}
	}
	a_to_b(a, b, pa_count - ra_count);
	if (ra_count >= rb_count)
	{
		while (++count < rb_count)
			rrr(a, b);
		while (++count <= ra_count)
			rra(a);
	}
	else if (ra_count < rb_count)
	{
		while (++count < ra_count)
			rrr(a, b);
		while (++count <= rb_count)
			rrb(b);
	}
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
}

void	a_to_b(t_stack *a, t_stack *b, int count)
{
	int 	small_pivot;
	int 	large_pivot;
	int 	ra_count;
	int 	rb_count;
	int 	pb_count;

	if (count <= 3)
	{
		sort_a_under_three(a, count);
		return ;
	}
	small_pivot = get_small_pivot(a, count);
	large_pivot = get_large_pivot(a, count);
	pb_count = 0;
	rb_count = 0;
	ra_count = 0;

	while (count--)
	{
		if (a->top->data <= large_pivot)
		{
			pb(a, b);
			pb_count++;
			if (b->top->data >= small_pivot)
			{
				rb(b);
				rb_count++;
			}
		}
		else
		{
			ra(a);
			ra_count++;
		}
	}
	if (ra_count >= rb_count)
	{
		while (++count < rb_count)
			rrr(a, b);
		while (++count <= ra_count)
			rra(a);
	}
	else if (ra_count < rb_count)
	{
		while (++count < ra_count)
			rrr(a, b);
		while (++count <= rb_count)
			rrb(b);
	}
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
	b_to_a(a, b, pb_count - rb_count);
}