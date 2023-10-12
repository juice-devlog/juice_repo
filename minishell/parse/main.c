/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:43:33 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/12 19:39:42 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_process_list(t_process *process)
{
	while (process)
	{
		int i = 0;
		while (process->cmd[i])
			printf("str: %s\n", process->cmd[i++]);
		process = process->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_process	process;

	ac = 0;
	av = NULL;
	envp = NULL;
	while (1)
	{
		line = readline("minishell$ ");
		tokenize(&process, line, envp);
		print_process_list(&process);
		free(line);
	}
}
