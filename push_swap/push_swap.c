/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:23:58 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 10:39:52 by jooypark         ###   ########seoul.kr  */
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
	arr = parse_arg(argv, &num_cnt);
	a = init_stack_a(arr, num_cnt);
	b = init_stack_b();
	if (!is_sorted(a, 'a', num_cnt))
		start_sorting(a, b, num_cnt);
	free_stack(a, b);
}
