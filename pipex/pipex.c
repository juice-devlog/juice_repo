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

	if (pipe(fd) == -1)
		handle_process_error(cmd, "PIPE ERROR");
	pid = fork();
	if (pid < 0)
		handle_process_error(cmd, "FORK ERROR");
	else if (pid == 0)
		first_child_process(infile, fd, cmd, envp);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid < 0)
		handle_process_error(cmd, "FORK ERROR");
	else if (pid == 0)
		second_child_process(outfile, fd, cmd, envp);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	close(infile);
	close(outfile);
	free_cmd(cmd);
}

char	*find_path(char **cmd, char **paths)
{
	int		i;
	char	*cmd_with_slash;
	char	*cmd_path;

	if (!cmd || !cmd[0])
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_with_slash = ft_strjoin("/", cmd[0]);
		if (i == 0)
			cmd_path = ft_strjoin(&paths[i][5], cmd_with_slash);
		else
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
	cmd->cmd2 = ft_split(av[3], ' ');
	cmd->cmd1_path = find_path(cmd->cmd1, paths);
	cmd->cmd2_path = find_path(cmd->cmd2, paths);
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

int	main(int ac, char **av, char **envp)
{
	int		infile;
	int		outfile;
	t_cmd	cmd;

	if (ac != 5)
		return (print_error_msg("Invalid number of arguments\n"));
	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		print_system_error("FILE ERROR");
	parse_env(av, envp, &cmd);
	pipex(infile, outfile, &cmd, envp);
	return (0);
}
