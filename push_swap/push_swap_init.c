/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:26:20 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 08:16:40 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = num;
	new->next = 0;
	return (new);
}

t_stack	*init_stack_b(void)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	b->top = NULL;
	return (b);
}

t_stack	*init_stack_a(int *arr, int num_cnt)
{
	t_stack	*a;
	t_node	*cur;
	int		i;

	a = (t_stack *)malloc(sizeof(t_stack));
	i = 0;
	a->top = create_new_node(arr[i++]);
	cur = a->top;
	while (i < num_cnt)
	{
		cur->next = create_new_node(arr[i]);
		cur = cur->next;
		i++;
	}
	free(arr);
	return (a);
}

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->small_pivot = 0;
	info->large_pivot = 0;
	info->p_cnt = 0;
	info->ra_cnt = 0;
	info->rb_cnt = 0;
	return (info);
}
