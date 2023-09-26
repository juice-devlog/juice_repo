/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 08:09:34 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/24 19:00:38 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			i++;
		if (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			count++;
		while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			i++;
	}
	return (count);
}

char	*make_num(int *arr, char *s, int len)
{
	char	*num;
	int		i;

	if (len == 0 || len > 11)
		display_error(arr, 0);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		display_error(arr, num);
	i = -1;
	while (++i < len)
		num[i] = s[i];
	num[i] = 0;
	return (num);
}

int	check_atoi(int *arr, char *num)
{
	int			i;
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	if ((num[i] == '0' && num[i + 1]) || (num[i - 1] == '-' && !num[i]))
		display_error(arr, num);
	while (num[i])
	{
		if ('0' <= num[i] && num[i] <= '9')
			res = (res * 10) + (num[i++] - '0');
		else
			display_error(arr, num);
	}
	res *= sign;
	if ((res == 0 && i != 1) || (res < -2147483648 || res > 2147483647))
		display_error(arr, num);
	return (free(num), res);
}

void	fill_arr(char *s, int *arr, int *arr_idx)
{
	int	n;
	int	check_idx;

	while (*s)
	{
		while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
			s++;
		n = 0;
		while (s[n] && !((s[n] >= 9 && s[n] <= 13) || s[n] == 32))
			n++;
		arr[*arr_idx] = check_atoi(arr, make_num(arr, s, n));
		check_idx = 0;
		while (check_idx < *arr_idx)
		{
			if (arr[check_idx] == arr[*arr_idx])
				display_error(arr, 0);
			check_idx++;
		}
		(*arr_idx)++;
		s += n;
		while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
			s++;
	}
}

int	*parse_arg(char **argv, int *num_cnt)
{
	int	i;
	int	*arr;
	int	arr_idx;

	i = 0;
	*num_cnt = 0;
	while (argv[++i])
		*num_cnt += count_numbers(argv[i]);
	arr = (int *)malloc(sizeof(int) * *num_cnt);
	if (!arr)
		display_error(arr, 0);
	i = 0;
	arr_idx = 0;
	while (argv[++i])
		fill_arr(argv[i], arr, &arr_idx);
	return (arr);
}
