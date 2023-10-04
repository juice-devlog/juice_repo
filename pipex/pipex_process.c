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

void	first_child_process(int infile, int *fd, t_cmd *cmd, char **envp)
{
	close(fd[0]);
	if (dup2(infile, STDIN_FILENO) == -1)
		handle_process_error(cmd, "DUP2 ERROR");
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		handle_process_error(cmd, "DUP2 ERROR");
	close(fd[1]);
	if (!cmd->cmd1 || !cmd->cmd1_path)
		handle_process_error(cmd, "COMMAND ERROR");
	if (execve(cmd->cmd1_path, cmd->cmd1, envp) == -1)
		handle_process_error(cmd, "EXECUTE ERROR");
}

void second_child_process(int outfile, int *fd, t_cmd *cmd, char **envp)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		handle_process_error(cmd, "DUP2 ERROR");
	close(fd[0]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		handle_process_error(cmd, "DUP2 ERROR");
	close(outfile);
	if (!cmd->cmd2 || !cmd->cmd2_path)
		handle_process_error(cmd, "COMMAND ERROR");
	if (execve(cmd->cmd2_path, cmd->cmd2, envp) == -1)
		handle_process_error(cmd, "EXECUTE ERROR");
}
