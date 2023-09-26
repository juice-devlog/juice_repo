/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_reverse_rotate.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:48:55 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 06:48:55 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	reverse_rotate(t_stack *s)
{
	t_node	*new_last;
	t_node	*last;

	last = s->top;
	while (last->next)
		last = last->next;
	new_last = s->top;
	if (new_last != last)
	{
		while (new_last->next != last)
			new_last = new_last->next;
		new_last->next = 0;
		last->next = s->top;
		s->top = last;
	}
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
