#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_cmd
{
	char **cmd1;
	char **cmd2;
	char *cmd1_path;
	char *cmd2_path;

}	t_cmd;

int ft_strncmp(const char *str1, const char *str2, size_t n);
char **ft_split(char const *s, char c);
char *ft_strjoin(char const *s1, char const *s2);

#endif