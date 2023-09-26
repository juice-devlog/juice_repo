/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 08:34:30 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 08:36:53 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(int *arr, char *num)
{
	if (arr)
		free(arr);
	if (num)
		free(num);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *a, t_stack *b)
{
	t_node	*cur;
	t_node	*next;

	cur = a->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(a);
	free(b);
}
