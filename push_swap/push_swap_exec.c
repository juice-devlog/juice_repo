/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:49:16 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 06:49:16 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	start_sorting(t_stack *a, t_stack *b, int count)
{
	t_info	*info;

	if (count <= 3)
	{
		sort_a_under_three(a, count);
		return ;
	}
	info = init_info();
	get_pivot(a, count, info);
	while (count--)
		start_sorting_while(a, b, &count, info);
	a_to_b(a, b, info->ra_cnt);
	b_to_a(a, b, info->p_cnt - info->rb_cnt);
	b_to_a(a, b, info->rb_cnt);
	free(info);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	t_info	*info;

	if (count <= 3)
	{
		sort_b_under_three(b, count);
		while (count--)
			pa(a, b);
		return ;
	}
	info = init_info();
	get_pivot(b, count, info);
	while (count--)
		b_to_a_while(a, b, &count, info);
	a_to_b(a, b, info->p_cnt - info->ra_cnt);
	merge_rra_rrb_count(a, b, info->ra_cnt, info->rb_cnt);
	a_to_b(a, b, info->ra_cnt);
	b_to_a(a, b, info->rb_cnt);
	free(info);
}

void	a_to_b(t_stack *a, t_stack *b, int count)
{
	t_info	*info;

	if (count <= 3)
	{
		sort_a_under_three(a, count);
		return ;
	}
	info = init_info();
	get_pivot(a, count, info);
	while (count--)
		a_to_b_while(a, b, &count, info);
	merge_rra_rrb_count(a, b, info->ra_cnt, info->rb_cnt);
	a_to_b(a, b, info->ra_cnt);
	b_to_a(a, b, info->rb_cnt);
	b_to_a(a, b, info->p_cnt - info->rb_cnt);
	free(info);
}
