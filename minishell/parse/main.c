/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:43:33 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/09 22:14:08 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int main(int ac, char **av, char **envp)
{
	char	*line;
	t_token	*token;

	ac = 0;
	av = NULL;
	envp = NULL;
	token = (t_token *)malloc(sizeof(t_token));
	while (1)
	{
		line = readline("minishell$ ");
		token->str = line;
		token->type = T_NONE;
		token->next = NULL;
		tokenize(token, envp);
		while (token)
		{
			printf("%s, %d\n", token->str, token->type);
			token = token->next;
		}
		free(line);
	}
}
