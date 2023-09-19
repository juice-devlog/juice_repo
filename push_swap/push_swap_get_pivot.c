#include "push_swap.h"

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

void	get_pivot(t_stack *s, int count, int *pivot_small_large)
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
	pivot_small_large[0] = arr[count / 3];
	pivot_small_large[1] = arr[count / 3 * 2];
}

// int get_large_pivot(t_stack *s, int count)
// {
// 	int *arr;
// 	t_node *cur;
// 	int i;

// 	i = -1;
// 	arr = (int *)malloc(sizeof(int) * count);
// 	cur = s->top;
// 	while (++i < count)
// 	{
// 		arr[i] = cur->data;
// 		cur = cur->next;
// 	}
// 	quick_sort(arr, 0, count - 1);
// 	return (arr[count / 3 * 2]);
// }