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

char	*create_new_str(char *s, int n)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

t_token	*add_new_token(t_token *prev_token, char *new_str, int new_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->str = new_str;
	new_token->type = new_type;
	if (prev_token == NULL)
		new_token->next = NULL;
	else
	{
		new_token->next = prev_token->next;
		prev_token->next = new_token;
	}
	return (new_token);
}

// void	parse_quote(t_token *token)
// {
// 	int		i;
// 	int		j;
// 	char	*new_str;

// 	while (token)
// 	{
// 		if (check_quote(token->str) && token->type == T_NONE)
// 		{
// 			i = 0;
// 			while (token->str[i])
// 			{
// 				if (token->str[i] == '\'' || token->str[i] == '"')
// 				{
// 					j = i + 1;
// 					while (token->str[j] != token->str[i])
// 						j++;
// 					new_str = create_new_str(&(token->str[i + 1]), j - i - 1);
// 					if (token->str[i] == '\'')
// 						add_new_token(token, new_str, T_ARG);
// 					else
// 						add_new_token(token, new_str, T_NONE);
// 					i = j;
// 				}
// 				i++;
// 			}
// 		}
// 		token = token->next;
// 	}
// }

int main()
{
	t_token *token;
	t_token *backup;
	
	token = (t_token *)malloc(sizeof(t_token));
	token->
	token = add_new_token(NULL, "hi", T_ARG);
	backup = token;
	token = token->next;
	add_new_token(token, "hello", T_NONE);
	add_new_token(token, "good", T_ARG);
	while (backup)
	{
		printf("%s, %d\n", backup->str, backup->type);
		backup = backup->next;
	}
}