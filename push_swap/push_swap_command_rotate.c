/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:49:02 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 06:49:02 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	first = s->top;
	last = s->top;
	while (last->next)
		last = last->next;
	if (first != last)
	{
		last->next = first;
		s->top = first->next;
		first->next = 0;
	}
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
