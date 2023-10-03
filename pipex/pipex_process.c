/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:48:53 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/03 13:07:40 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_process(int *fd, pid_t *pid)
{
	if (pipe(fd) == -1)
		return ;
	*pid = fork();
	if (*pid < 0)
		return ;
}

void	input_redirection(int infile, int *fd)
{
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(fd[1]);
}

void	output_redirection(int outfile, int *fd)
{
	close(fd[0]);
	close(fd[1]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	execute_command(char **cmd, char *cmd_path, char **envp)
{
	if (execve(cmd_path, cmd, envp) == -1)
	{
		strerror(127);
		exit(127);
	}
}

void	parent_process(int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}
