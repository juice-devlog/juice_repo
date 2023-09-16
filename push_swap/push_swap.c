/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:23:58 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/15 21:56:07 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	int		num_cnt;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(0);
	arr = parse_arg(argc, argv, &num_cnt);
	int	i = 0;
	while (i < num_cnt)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("count: %d\n", num_cnt);
	a = init_stack_a(arr, num_cnt);
	b = init_stack_b();
	a_to_b(a, b, num_cnt);
	printf("a: ");
	t_node *cur = a->top;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\nb: ");
	cur = b->top;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");

}