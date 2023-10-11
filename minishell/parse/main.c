/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:43:33 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/11 19:57:13 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_token_list(t_token *token)
{
	while (token)
	{
		printf("str: %s, type: %d\n", token->str, token->type);
		token = token->next;
	}
}

int main(int ac, char **av, char **envp)
{
	char	*line;
	t_token	token;

	ac = 0;
	av = NULL;
	envp = NULL;
	while (1)
	{
		line = readline("minishell$ ");
		tokenize(&token, line, envp);
		print_token_list(&token);
		free(line);
	}
}
