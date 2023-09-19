#include "./push_swap.h"

void	start_sorting(t_stack *a, t_stack *b, int count)
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
	////printf("small: %d, large: %d\n", small_pivot, large_pivot);
	while (count--)
	{
		if (a->top->data <= large_pivot)
		{
			pb(a, b);
			pb_count++;
			if (b->top->data <= small_pivot)
			{
				if (a->top && a->top->data > large_pivot && count > 0)
				{
					rr(a, b);
					//if (a->top)
						ra_count++;
					//if (b->top)
						rb_count++;
					count--;
				}
				else
				{
					rb(b);
					rb_count++;
				}
			}
		}
		else
		{
			ra(a);
			ra_count++;
		}
			t_node *cur = a->top;
		while (cur)
		{
			//printf("%d->", cur->data);
			cur = cur->next;
		}
		//printf("\nb: ");
		cur = b->top;
		while (cur)
		{
			//printf("%d->", cur->data);
			cur = cur->next;
		}
		//printf("\n---------\n");
	}
	//printf("ra_count : %d, rb_count : %d, pb_count : %d\n", ra_count, rb_count, pb_count);
	//printf("start sorting\n");
	//printf("a: ");

	//printf("\n");

	a_to_b(a, b, ra_count);
	b_to_a(a, b, pb_count - rb_count);
	b_to_a(a, b, rb_count);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int 	small_pivot;
	int 	large_pivot;
	int 	ra_count;
	int 	rb_count;
	int 	pa_count;

	//printf("new b_to_a\n");
	if (count <= 3)
	{
		sort_b_under_three(b, count);
		while (count--)
			pa(a, b);
		//printf("b_to_a under three sort\n");
		//printf("a: ");
		t_node *cur = a->top;
		while (cur)
		{
			//printf("%d->", cur->data);
			cur = cur->next;
		}
		//printf("\nb: ");
		cur = b->top;
		while (cur)
		{
			//printf("%d->", cur->data);
			cur = cur->next;
		}
		//printf("\n");
		return ;
	}
	small_pivot = get_small_pivot(b, count);
	large_pivot = get_large_pivot(b, count);
	pa_count = 0;
	rb_count = 0;
	ra_count = 0;
	//printf("small: %d, large: %d\n", small_pivot, large_pivot);
	while (count--)
	{
		if (b->top->data >= small_pivot)
		{
			pa(a, b);
			pa_count++;
			if (a->top->data <= large_pivot)
			{
				if (a->top && a->top->data < small_pivot && count > 0)
				{
					rr(a, b);
					//if (a->top)
						ra_count++;
					//if (b->top)
						rb_count++;
					count--;
				}
				else 
				{
					ra(a);
					ra_count++;
				}
			}
		}
		else
		{
			rb(b);
			rb_count++;
		}
	}
	//printf("b_to_a\n");
	//printf("a: ");
	t_node *cur = a->top;
	while (cur)
	{
		//printf("%d->", cur->data);
		cur = cur->next;
	}
	//printf("\nb: ");
	cur = b->top;
	while (cur)
	{
		//printf("%d->", cur->data);
		cur = cur->next;
	}
	//printf("\n");
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

	// //printf("new a_to_b count: %d\n", count);
	if (count <= 3)
	{
		sort_a_under_three(a, count);
		//printf("a_to_b under three sort\n");
		//printf("a: ");
		t_node *cur = a->top;
		while (cur)
		{
			//printf("%d->", cur->data);
			cur = cur->next;
		}
		//printf("\nb: ");
		cur = b->top;
		while (cur)
		{
			//printf("%d->", cur->data);
			cur = cur->next;
		}
		//printf("\n");
		return ;
	}
	small_pivot = get_small_pivot(a, count);
	large_pivot = get_large_pivot(a, count);
	pb_count = 0;
	rb_count = 0;
	ra_count = 0;
	// //printf("small: %d, large: %d\n", small_pivot, large_pivot);
	while (count--)
	{
		if (a->top->data <= large_pivot)
		{
			pb(a, b);
			pb_count++;
			if (b->top->data >= small_pivot)
			{
				if (a->top && a->top->data > large_pivot && count > 0)
				{
					rr(a, b);
					//if (a->top->next)
						ra_count++;
					//if (b->top->next)
						rb_count++;
					count--;
				}
				else
				{
					rb(b);
					rb_count++;
				}
			}
		}
		else
		{
			ra(a);
			ra_count++;
		}
	}
	// //printf("ra: %d, rb: %d, count: %d\n", ra_count, rb_count, count);
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
	//printf("a_to_b\n");
	//printf("a: ");
	t_node *cur = a->top;
	while (cur)
	{
		//printf("%d->", cur->data);
		cur = cur->next;
	}
	//printf("\nb: ");
	cur = b->top;
	while (cur)
	{
		//printf("%d->", cur->data);
		cur = cur->next;
	}
	//printf("\n");
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
	b_to_a(a, b, pb_count - rb_count);
}