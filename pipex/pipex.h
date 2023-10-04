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

char	*find_path(char **cmd, char **paths);
void	parse_env(char **av, char **envp, t_cmd *info);
void	pipex(int infile, int outfile, t_cmd *info, char **envp);

void first_child_process(int infile, int *fd, t_cmd *cmd, char **envp);
void second_child_process(int outfile, int *fd, t_cmd *cmd, char **envp);

void free_cmd(t_cmd *cmd);
int print_error_msg(char *msg);
void handle_error(char *msg);
void handle_process_error(t_cmd *cmd, char *msg);

#endif