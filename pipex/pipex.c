/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:36:58 by jooypark          #+#    #+#             */
/*   Updated: 2023/09/25 11:36:58 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pipex(int infile, int outfile, t_cmd cmd, char **envp)
{
	int fd[2];
	pid_t pid;

	if(pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid < 0)
		return ;
	if (!pid)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(infile);
		execve(cmd.cmd1_path, cmd.cmd1, envp);
	}
	else
	{
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[1]);
		close(outfile);
		execve(cmd.cmd2_path, cmd.cmd2, envp);
	}
}

char *find_path(char *cmd, char **paths)
{
	int i;
	char *cmd_with_slash;
	char *cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_with_slash = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(paths[i], cmd_with_slash);
		free(cmd_with_slash);
		if (access(cmd_path, X_OK) != -1)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

int parse_env(char **av, char **envp, t_cmd *cmd)
{
	int	i;
	char **paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	cmd->cmd1 = ft_split(av[2], ' ');
	cmd->cmd2 = ft_split(av[3], ' ');
	cmd->cmd1_path = find_path(cmd->cmd1[0], paths);
	cmd->cmd2_path = find_path(cmd->cmd2[0], paths);
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

int main(int ac, char **av, char **envp)
{
	int infile;
	int outfile;
	t_cmd cmd;

	if (ac != 5)
		return (-1);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		return (-1);
	parse_env(av, envp, &cmd);
	pipex(infile, outfile, cmd, envp);
	return (0);
}