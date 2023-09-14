#include "./push_swap.h"

void sort_a_under_three(t_stack *a)
{
	return;
}

void sort_b_under_three(t_stack *b)
{
	return;
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int search_small;
	int search_large;

	if (start >= end)
		return ;
	search_small = start + 1;
	search_large = end;
	while (search_small <= search_large)
	{
		while (arr[search_small] < arr[start] && search_small <= end)
			search_small++;
		while (arr[search_large] > arr[start] && search_large >= start)
			search_large--;
		if (search_small > search_large)
			ft_swap(&arr[start], &arr[search_large]);
		else
			ft_swap(&arr[search_small], &arr[search_large]);
	}
	quick_sort(arr, start, search_large);
	quick_sort(arr, search_large + 1, end);
}

int	get_small_pivot(t_stack *s, int count)
{
	int *arr;
	t_node *cur;
	int i;

	i = -1;
	arr = (int *)malloc(sizeof(int) * count);
	cur = s->top;
	while (++i < count)
	{
		arr[i] = cur->data;
		cur = cur->next;
	}
	quick_sort(arr, 0, count - 1);
	return (arr[count / 3]);
}

int get_large_pivot(t_stack *s, int count)
{
	int *arr;
	t_node *cur;
	int i;

	i = -1;
	arr = (int *)malloc(sizeof(int) * count);
	cur = s->top;
	while (++i < count)
	{
		arr[i] = cur->data;
		cur = cur->next;
	}
	quick_sort(arr, 0, count - 1);
	return (arr[count / 3 * 2]);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int 	small_pivot;
	int 	large_pivot;
	int 	ra_count;
	int 	rb_count;
	int 	pa_count;
	int		rrr_count;

	printf("new b_to_a start here !!\n");
	if (count <= 3)
	{
		sort_b_under_three(b);
		while (count--)
			pa(a, b);
		return;
	}
	else
	{
		small_pivot = get_small_pivot(b, count);
		printf("small: %d\n", small_pivot);
		large_pivot = get_large_pivot(b, count);
		printf("large: %d\n", large_pivot);
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
			t_node *a_check = a->top;
			t_node *b_check = b->top;
			printf("a: ");
			while (a_check)
			{
				printf("%d->", a_check->data);
				a_check = a_check->next;
			}
			printf("\nb: ");
			while (b_check)
			{
				printf("%d->", b_check->data);
				b_check = b_check->next;
			}
			printf("\n");
		}
		a_to_b(a, b, pa_count - ra_count);
		printf("ra_count: %d, rb_count: %d, pa_count: %d\n", ra_count, rb_count, pa_count);
		if (ra_count >= rb_count)
		{
			rrr_count = rb_count;
			while (++count < rrr_count)
				rrr(a, b);
			while (++count <= ra_count)
				rra(a);
		}
		else if (ra_count < rb_count)
		{
			rrr_count = ra_count;
			while (++count < rrr_count)
				rrr(a, b);
			while (++count <= rb_count)
				rrb(b);
		}
		t_node *a_check = a->top;
		t_node *b_check = b->top;
		printf("rrr -> a: ");
		while (a_check)
		{
			printf("%d->", a_check->data);
			a_check = a_check->next;
		}
		printf("\nrrr -> b: ");
		while (b_check)
		{
			printf("%d->", b_check->data);
			b_check = b_check->next;
		}
		printf("\n");
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
	int		rrr_count;

	printf("new a_to_b start here !!\n");
	if (count <= 3)
	{
		sort_a_under_three(a);
		return;
	}
	else
	{
		small_pivot = get_small_pivot(a, count);
		printf("small: %d\n", small_pivot);
		large_pivot = get_large_pivot(a, count);
		printf("large: %d\n", large_pivot);
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
			t_node *a_check = a->top;
			t_node *b_check = b->top;
			printf("a: ");
			while (a_check)
			{
				printf("%d->", a_check->data);
				a_check = a_check->next;
			}
			printf("\nb: ");
			while (b_check)
			{
				printf("%d->", b_check->data);
				b_check = b_check->next;
			}
			printf("\n");
		}
		printf("ra_count: %d, rb_count: %d, pb_count: %d\n", ra_count, rb_count, pb_count);
		if (ra_count >= rb_count)
		{
			rrr_count = rb_count;
			while (++count < rrr_count)
				rrr(a, b);
			while (++count <= ra_count)
				rra(a);
		}
		else if (ra_count < rb_count)
		{
			rrr_count = ra_count;
			while (++count < rrr_count)
				rrr(a, b);
			while (++count <= rb_count)
				rrb(b);
		}
		t_node *a_check = a->top;
		t_node *b_check = b->top;
		printf("rrr -> a: ");
		while (a_check)
		{
			printf("%d->", a_check->data);
			a_check = a_check->next;
		}
		printf("\nrrr -> b: ");
		while (b_check)
		{
			printf("%d->", b_check->data);
			b_check = b_check->next;
		}
		printf("\n");
	}
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
	b_to_a(a, b, pb_count - rb_count);
}