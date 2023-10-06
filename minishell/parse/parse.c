/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:43:33 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/06 22:16:58 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_single_quote(char *str)
{
	int	i;
	int	quote;

	i = 1;
	quote = 1;
	while (str[i])
	{
		if (str[i] == '\'')
			return (i);
		i++;
	}
	return (-1);
}

int	check_double_quote(char *str)
{
	int	i;
	int	quote;

	i = 1;
	quote = 1;
	while (str[i])
	{
		if (str[i] == '\'')
			return (i);
		i++;
	}
	return (-1);
}

void	add_token_info(char *str, t_token *token)
{
	int	i;
	int	start;
	int	end;
	int	quote;

	i = 0;
	while (str[i])
	{
		start = i;
		while (str[i] && (str[i] != '\'' || str[i] != '"' || str[i] != '$'))
			i++;
		end = i;
		token->type = 
		if (str[i] == '\'')
		{
			quote = check_single_quote(&str[i]);
			if (quote != -1)
				quote
	}
}

void	tokenize(char **strs)
{
	int		i;
	t_list	list;

	i = 0;
	while (strs[i])
	{
		add_token_info(strs[i], list.token);
		i++;
	}
}

int main(int ac, char **av, char **envp)
{
	char	*line;
	char	**strs;
	t_list	list;

	ac = 0;
	av = NULL;
	envp = NULL;
	while (1)
	{
		line = readline("minishell$ ");
		strs = ft_split(line, ' ');
		list = tokenize(strs);
		free(line);
	}
}