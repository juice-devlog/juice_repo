#include "parse.h"

void	tokenize(t_token *token, char **envp)
{
	parse_heredoc_limiter(token);
	parse_quote(token);
	parse_env(token, envp);
	parse_blank(token);
	parse_pipe(token);
	parse_redirection(token);
	parse_etc(token);
}
