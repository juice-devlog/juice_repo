/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:23:46 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/20 07:17:40 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_exist(int *arr, int arr_idx)
{
	int	check_idx;

	check_idx = 0;
	while (check_idx < arr_idx)
	{
		if (arr[check_idx] == arr[arr_idx])
			return (0);
		check_idx++;
	}
	return (1);
}

void	init_array(int *arr, char **argv)
{
	int		i;
	int		j;
	int		arr_idx;
	char	**numbers;

	i = 0;
	arr_idx = 0;
	while (argv[++i])
	{
		numbers = ft_split(argv[i], ' ');
		j = -1;
		while (numbers[++j])
		{
			arr[arr_idx] = check_atoi(arr, numbers, j);
			if (!check_exist(arr, arr_idx))
				free_on_parse_error(arr, numbers);
			arr_idx++;
		}
		free2(numbers);
	}
}

int	*parse_arg(char **argv, int *num_cnt)
{
	int			i;
	int			*arr;

	i = 0;
	*num_cnt = 0;
	while (argv[++i])
		*num_cnt += count_word(argv[i], ' ');
	arr = (int *)malloc(sizeof(int) * *num_cnt);
	init_array(arr, argv);
	return (arr);
}
