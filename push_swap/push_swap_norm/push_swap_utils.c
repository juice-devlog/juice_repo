/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:29:04 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/08 23:24:04 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	*put_word(char const *s, char c)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

void	free2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	display_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_on_parse_error(int *arr, char **numbers)
{
	free(arr);
	free2(numbers);
	display_error();
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;
	int		i;

	count = count_word(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			words[i] = put_word(s, c);
			if (words[i] == 0)
			{
				free2(words);
				return (0);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	words[i] = 0;
	return (words);
}

void	check_int(long long res, int i, int *arr, int idx, char **numbers)
{
	if ((res == 0 && i != 1) || (i >= 11)
		|| (res < -2147483648 || res > 2147483647))
		free_on_parse_error(arr, numbers);
}

int	check_atoi(int *arr, char **numbers, int idx)
{
	int			i;
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	if (numbers[idx][i] == '-')
	{
		sign = -1;
		i++;
	}
	if (numbers[idx][i] == '0' && numbers[idx][i + 1])
		free_on_parse_error(arr, numbers);
	while (numbers[idx][i])
	{
		if ('0' <= numbers[idx][i] && numbers[idx][i] <= '9')
			res = (res * 10) + (numbers[idx][i++] - '0');
		else
			free_on_parse_error(arr, numbers);
	}
	res *= sign;
	// if ((res == 0 && i != 1) || (i >= 11)
	// 	|| (res < -2147483648 || res > 2147483647))
	// 	free_on_parse_error(arr, numbers);
	return (check_int(res, i, arr, idx, numbers), (int)res);
}