#include "parse.h"

void	tokenize(t_process *process, char *line, char **envp)
{
	parse_heredoc_limiter(process);
	parse_quote(process);
	// parse_env(process, envp);
	// parse_blank(process);
	// parse_pipe(process);
	// parse_redirection(process);
	// parse_etc(process);
}
