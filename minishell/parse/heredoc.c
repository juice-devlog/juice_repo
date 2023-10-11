#include "parse.h"

int	is_heredoc(char *line)
{
	if (line[0] && line[1] && line[0] == '<' && line[1] == '<')
		return (1);
	return (0);
}

int	count_size(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_heredoc(&line[i]))
		{
			count++;
			i += 2;
		}
		else
		{
			count++;
			while (line[i] && !is_heredoc(&line[i]))
				i++;
		}
	}
	return (count);
}

char	*create_limiter(char *target, int start, int end)
{
	int		i;
	char	*tmp;
	char	*result;

	tmp = (char *)malloc(sizeof(char) * (end - start + 2));
	i = 0;
	while (start <= end)
	{
		if (target[start] == '$' && target[start + 1] == '"')
		{
			start++;
			continue ;
		}
		if (target[start] != '\'' && target[start] != '"')
			tmp[i++] = target[start];
		start++;
	}
	tmp[i] = 0;
	result = ft_strtrim(tmp, " \n\t");
	free(tmp);
	return (result);
}

char	*create_new_str(char *target, int start, int end)
{
	int		i;
	char	*tmp;
	char	*result;

	tmp = (char *)malloc(sizeof(char) * (end - start + 2));
	i = 0;
	while (start <= end)
	{
		tmp[i] = target[start];
		i++;
		start++;
	}
	tmp[i] = 0;
	result = ft_strtrim(tmp, " \n\t");
	free(tmp);
	return (result);
}

void	parse_heredoc_limiter(t_token *token)
{
	char	*target;
	int		count;
	int		start;
	int		end;
	int		i;

	target = token->str;
	count = count_size(target);
	i = 0;
	while (target[i])
	{
		start = i;
		if (is_heredoc(&target[i]))
		{
			end = i + 1;
			insert(token, create_new_str(target, start, end), T_REDIR);
			token = token->next;
			i = end + 1;
		}
		else
		{
			while (target[i] && !is_heredoc(&target[i]))
				i++;
			end = i - 1;
			if (ft_strncmp(token->str, "<<", 2) == 0)
				insert(token, create_limiter(target, start, end), T_LIMITER);
			else
				insert(token, create_new_str(target, start, end), T_NONE);
			token = token->next;
		}
	}
}
