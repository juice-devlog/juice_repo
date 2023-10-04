/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:44:04 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/04 11:44:04 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_cmd(t_cmd *cmd)
{
	int i;

	i = -1;
	while (cmd->cmd1[i++])
		free(cmd->cmd1[i]);
	free(cmd->cmd1);
	free(cmd->cmd1_path);
	i = -1;
	while (cmd->cmd2[i++])
		free(cmd->cmd2[i]);
	free(cmd->cmd2);
	free(cmd->cmd2_path);
}

int	print_error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	handle_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	handle_process_error(t_cmd *cmd, char *msg)
{
	free_cmd(cmd);
	handle_error(msg);
}