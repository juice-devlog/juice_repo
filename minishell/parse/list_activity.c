#include "parse.h"

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

void	add_first(t_token *head, char *new_str, int new_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->str = new_str;
	new_token->type = new_type;
	new_token->next = head;
	head = new_token;
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


void	delete(t_token *prev_token)
{
	t_token	*delete_token;

	delete_token = prev_token->next;
	prev_token->next = delete_token->next;
	free_token(delete_token);
}