#include "push_swap.h"

void	start_sorting_while(t_stack *a, t_stack *b, int *count, int *pivot_small_large, int *count_pb_ra_rb)
{
	if (a->top->data <= pivot_small_large[1])
	{
		pb(a, b);
		count_pb_ra_rb[0]++;
		if (b->top->data <= pivot_small_large[0])
		{
			if (a->top && a->top->data > pivot_small_large[1] && *count > 0)
			{
				rr(a, b);
				count_pb_ra_rb[1]++;
				count_pb_ra_rb[2]++;
				(*count)--;
			}
			else
			{
				rb(b);
				count_pb_ra_rb[2]++;
			}
		}
	}
	else
	{
		ra(a);
		count_pb_ra_rb[1]++;
	}
}

void b_to_a_while(t_stack *a, t_stack *b, int *count, int *pivot_small_large, int *count_pa_ra_rb)
{
	if (b->top->data >= pivot_small_large[0])
	{
		pa(a, b);
		count_pa_ra_rb[0]++;
		if (a->top->data <= pivot_small_large[1])
		{
			if (a->top && a->top->data < pivot_small_large[0] && *count > 0)
			{
				rr(a, b);
				count_pa_ra_rb[1]++;
				count_pa_ra_rb[2]++;
				(*count)--;
			}
			else
			{
				ra(a);
				count_pa_ra_rb[1]++;
			}
		}
	}
	else
	{
		rb(b);
		count_pa_ra_rb[2]++;
	}
}

void a_to_b_while(t_stack *a, t_stack *b, int *count, int *pivot_small_large, int *count_pb_ra_rb)
{
	if (a->top->data <= pivot_small_large[1])
	{
		pb(a, b);
		count_pb_ra_rb[0]++;
		if (b->top->data >= pivot_small_large[0])
		{
			if (a->top && a->top->data > pivot_small_large[1] && *count > 0)
			{
				rr(a, b);
				count_pb_ra_rb[1]++;
				count_pb_ra_rb[2]++;
				(*count)--;
			}
			else
			{
				rb(b);
				count_pb_ra_rb[2]++;
			}
		}
	}
	else
	{
		ra(a);
		count_pb_ra_rb[1]++;
	}
}

void	merge_rra_rrb_count(t_stack *a, t_stack *b, int ra_count, int rb_count)
{
	int i;

	i = -1;
	if (ra_count >= rb_count)
	{
		while (++i < rb_count)
			rrr(a, b);
		while (++i <= ra_count)
			rra(a);
	}
	else
	{
		while (++i < ra_count)
			rrr(a, b);
		while (++i <= rb_count)
			rrb(b);
	}
}