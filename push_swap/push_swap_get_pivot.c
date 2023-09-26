/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_get_pivot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:49:19 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 08:16:59 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	search_small;
	int	search_large;

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

void	get_pivot(t_stack *s, int count, t_info *info)
{
	int		*arr;
	t_node	*cur;
	int		i;

	i = -1;
	arr = (int *)malloc(sizeof(int) * count);
	cur = s->top;
	while (++i < count)
	{
		arr[i] = cur->data;
		cur = cur->next;
	}
	quick_sort(arr, 0, count - 1);
	info->small_pivot = arr[count / 3];
	info->large_pivot = arr[count / 3 * 2];
	free(arr);
}
