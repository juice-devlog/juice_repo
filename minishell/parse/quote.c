#include "parse.h"

int	check_quote(char *cmd_line)
{
	int		i;
	int		top;
	int		quote_cnt;
	char	*quote_stack;

	i = 0;
	quote_cnt = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\'' || cmd_line[i] == '"')
			quote_cnt++;
		i++;
	}
	quote_stack = (char *)malloc(sizeof(char) * (quote_cnt + 1));
	i = 0;
	top = -1;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\'' || cmd_line[i] == '"')
		{
			if (quote_stack[top] != cmd_line[i])
				quote_stack[++top] = cmd_line[i];
			else
				top--;
		}
		i++;
	}
	free(quote_stack);
	if (top != -1)
		return (0);
	return (1);
}

t_token *split_by_quote(t_token *token, char *target)
{
	int	i;
	int	end;

	i = 0;
	while (target[i])
	{
		if (target[i] == '\'' || target[i] == '"')
		{
			end = i + 1;
			while (target[end] != target[i])
				end++;
			if (target[i] == '\'')
				printf("%s\n", create_new_str(target, i, end));
				//insert(token, create_new_str(target, i, end), T_SQUOTE);
			else
				printf("%s\n", create_new_str(target, i, end));
				//insert(token, create_new_str(target, i, end), T_DQUOTE);
			i = end;
			//token = token->next;
		}
		i++;
	}
	return (token->next);
}

void	parse_quote(t_token *token)
{
	while (token)
	{
		printf("%s\n", token->str);
		if (check_quote(token->str) && token->type == T_NONE)
			token = split_by_quote(token, token->str);
		else if (check_quote(token->str) && token->type != T_NONE)
			token = token->next;
		else if (!check_quote(token->str))
			exit(1);
	}
}
