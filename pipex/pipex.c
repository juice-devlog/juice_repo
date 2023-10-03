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

void	pipex(int infile, int outfile, t_cmd *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	i = 0;
	while (i < 2)
	{
		create_process(fd, &pid);
		if (!pid && i == 0)
		{
			input_redirection(infile, fd);
			execute_command(cmd->cmd1, cmd->cmd1_path, envp);
		}
		else if (!pid && i == 1)
		{
			output_redirection(outfile, fd);
			execute_command(cmd->cmd2, cmd->cmd2_path, envp);
		}
		else
			parent_process(fd);
		i++;
	}
}

char	*find_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_with_slash;
	char	*cmd_path;

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

void	parse_env(char **av, char **envp, t_cmd *cmd)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	cmd->cmd1 = ft_split(av[2], ' ');
	cmd->cmd1_path = find_path(cmd->cmd1[0], paths);
	cmd->cmd2 = ft_split(av[3], ' ');
	cmd->cmd2_path = find_path(cmd->cmd2[0], paths);
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

void cl()
{
	system("leaks pipex");
}

int main(int ac, char **av, char **envp)
{
	int infile;
	int outfile;
	t_cmd cmd;

	atexit(cl);
	if (ac != 5)
		return (-1);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		perror("FILE ERROR");
		exit(0);
	}
	parse_env(av, envp, &cmd);
	pipex(infile, outfile, &cmd, envp);
	free_cmd(cmd);
	return (0);
}