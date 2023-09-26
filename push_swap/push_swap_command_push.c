/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:48:46 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 06:48:46 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push(t_stack *s1, t_stack *s2)
{
	t_node	*top_s2;

	top_s2 = s2->top;
	s2->top = top_s2->next;
	top_s2->next = s1->top;
	s1->top = top_s2;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
