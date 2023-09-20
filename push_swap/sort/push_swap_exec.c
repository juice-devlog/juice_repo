#include "./push_swap.h"

void	start_sorting(t_stack *a, t_stack *b, int count)
{
	int pivot_small_large[2];
	int count_pb_ra_rb[3];

	if (count <= 3)
	{
		sort_a_under_three(a, count);
		return ;
	}
	get_pivot(a, count, pivot_small_large);
	count_pb_ra_rb[0] = 0;
	count_pb_ra_rb[1] = 0;
	count_pb_ra_rb[2] = 0;
	while (count--)
		start_sorting_while(a, b, &count, pivot_small_large, count_pb_ra_rb);
	a_to_b(a, b, count_pb_ra_rb[1]);
	b_to_a(a, b, count_pb_ra_rb[0] - count_pb_ra_rb[2]);
	b_to_a(a, b, count_pb_ra_rb[2]);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int pivot_small_large[2];
	int count_pa_ra_rb[3];

	if (count <= 3)
	{
		sort_b_under_three(b, count);
		while (count--)
			pa(a, b);
		return ;
	}
	get_pivot(b, count, pivot_small_large);
	count_pa_ra_rb[0] = 0;
	count_pa_ra_rb[1] = 0;
	count_pa_ra_rb[2] = 0;
	while (count--)
		b_to_a_while(a, b, &count, pivot_small_large, count_pa_ra_rb);
	a_to_b(a, b, count_pa_ra_rb[0] - count_pa_ra_rb[1]);
	merge_rra_rrb_count(a, b, count_pa_ra_rb[1], count_pa_ra_rb[2]);
	a_to_b(a, b, count_pa_ra_rb[1]);
	b_to_a(a, b, count_pa_ra_rb[2]);
}

void	a_to_b(t_stack *a, t_stack *b, int count)
{
	int pivot_small_large[2];
	int count_pb_ra_rb[3];

	if (count <= 3)
	{
		sort_a_under_three(a, count);
		return ;
	}
	get_pivot(a, count, pivot_small_large);
	count_pb_ra_rb[0] = 0;
	count_pb_ra_rb[1] = 0;
	count_pb_ra_rb[2] = 0;
	while (count--)
		a_to_b_while(a, b, &count, pivot_small_large, count_pb_ra_rb);
	merge_rra_rrb_count(a, b, count_pb_ra_rb[1], count_pb_ra_rb[2]);
	a_to_b(a, b, count_pb_ra_rb[1]);
	b_to_a(a, b, count_pb_ra_rb[2]);
	b_to_a(a, b, count_pb_ra_rb[0] - count_pb_ra_rb[2]);
}