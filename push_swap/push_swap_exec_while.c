/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exec_while.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:49:12 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 06:49:12 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting_while(t_stack *a, t_stack *b, int *count, t_info *info)
{
	if (a->top->data <= info->large_pivot)
	{
		pb(a, b);
		info->p_cnt++;
		if (b->top->data <= info->small_pivot)
		{
			if (a->top && a->top->data > info->large_pivot && *count > 0)
			{
				rr(a, b);
				info->ra_cnt++;
				info->rb_cnt++;
				(*count)--;
			}
			else
			{
				rb(b);
				info->rb_cnt++;
			}
		}
	}
	else
	{
		ra(a);
		info->ra_cnt++;
	}
}

void	b_to_a_while(t_stack *a, t_stack *b, int *count, t_info *info)
{
	if (b->top->data >= info->small_pivot)
	{
		pa(a, b);
		info->p_cnt++;
		if (a->top->data <= info->large_pivot)
		{
			if (a->top && a->top->data < info->small_pivot && *count > 0)
			{
				rr(a, b);
				info->ra_cnt++;
				info->rb_cnt++;
				(*count)--;
			}
			else
			{
				ra(a);
				info->ra_cnt++;
			}
		}
	}
	else
	{
		rb(b);
		info->rb_cnt++;
	}
}

void	a_to_b_while(t_stack *a, t_stack *b, int *count, t_info *info)
{
	if (a->top->data <= info->large_pivot)
	{
		pb(a, b);
		info->p_cnt++;
		if (b->top->data >= info->small_pivot)
		{
			if (a->top && a->top->data > info->large_pivot && *count > 0)
			{
				rr(a, b);
				info->ra_cnt++;
				info->rb_cnt++;
				(*count)--;
			}
			else
			{
				rb(b);
				info->rb_cnt++;
			}
		}
	}
	else
	{
		ra(a);
		info->ra_cnt++;
	}
}

void	merge_rra_rrb_count(t_stack *a, t_stack *b, int ra_count, int rb_count)
{
	int	i;

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
