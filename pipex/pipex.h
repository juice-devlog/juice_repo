#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;

}	t_cmd;

char	*find_path(char *cmd, char **paths);
void	parse_env(char **av, char **envp, t_cmd *info);
void	pipex(int infile, int outfile, t_cmd *info, char **envp);

void	create_process(int *fd, pid_t *pid);
void	input_redirection(int infile, int *fd);
void	output_redirection(int outfile, int *fd);
void	execute_command(char **cmd, char *cmd_path, char **envp);
void	parent_process(int *fd);

#endif