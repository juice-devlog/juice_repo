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

void	free_token(t_token *token)
{
	free(token->str);
	free(token);
}

void	insert(t_token *prev_token, char *new_str, int new_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->str = new_str;
	new_token->type = new_type;
	new_token->next = prev_token->next;
	prev_token->next = new_token;
}

t_token *add_first(t_token *head, char *new_str, int new_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->str = new_str;
	new_token->type = new_type;
	new_token->next = head;
	head = new_token;
	return (new_token);
}

void	add_last(t_token *head, char *new_str, int new_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->str = new_str;
	new_token->type = new_type;
	while (head->next)
		head = head->next;
	head->next = new_token;
	new_token->next = NULL;
}

void	delete_first(t_token *head)
{
	t_token *new_head;

	new_head = head->next;
	head->next = NULL;
	head = new_head;
}

void	delete(t_token *prev_token)
{
	t_token	*delete_token;

	delete_token = prev_token->next;
	prev_token->next = delete_token->next;
}

void	parse_quote(t_token *token)
{
	int		i;
	int		j;
	char	*new_str;

	while (token)
	{
		if (check_quote(token->str) && token->type == T_NONE)
		{
			i = 0;
			while (token->str[i])
			{
				if (token->str[i] == '\'' || token->str[i] == '"')
				{
					j = i + 1;
					while (token->str[j] != token->str[i])
						j++;
					new_str = create_new_str(&(token->str[i + 1]), j - i - 1);
					if (token->str[i] == '\'')
						add_new_token(token, new_str, T_ARG);
					else
						add_new_token(token, new_str, T_NONE);
					i = j;
				}
				i++;
			}
		}
		token = token->next;
	}
}

int main()
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	token->str = "first";
	token->type = T_NONE;
	token->next = NULL;
	token = add_first(token, "hi", T_ARG);
	insert(token, "hello", T_NONE);
	add_last(token, "good", T_ARG);
	delete_first(token);
	while (token)
	{
		printf("%s, %d\n", token->str, token->type);
		token = token->next;
	}
}
