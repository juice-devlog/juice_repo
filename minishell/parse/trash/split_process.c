/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:18:56 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/09 23:05:58 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_special_symbol(char c)
{
	if (c == '<')
		return (T_LEFT_REDIR);
	else if (c == '>')
		return (T_RIGHT_REDIR);
	else if (c == '&')
		return (T_AMPERSAND);
	else if (c == '|')
		return (T_PIPE);
	else if (c == ';')
		return (T_COLON);
	else
		return (T_NONE);
}

int	count_cmd_line(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s && (is_special_symbol(*s) != T_NONE))
			count++;
		while (*s && (is_special_symbol(*s) != T_NONE))
			s++;
		if (*s && (is_special_symbol(*s) == T_NONE))
			count++;
		while (*s && (is_special_symbol(*s) == T_NONE))
			s++;
	}
	return (count);
}

char	*put_cmd_line(char *s, int type)
{
	char	*cmd;
	int		len;
	int		i;

	len = 0;
	while (s[len] && (is_special_symbol(s[len]) == type))
		len++;
	cmd = (char *)malloc((len + 1) * sizeof(char));
	if (!cmd)
		return (0);
	i = 0;
	while ((is_special_symbol(s[i]) == type) && s[i])
	{
		cmd[i] = s[i];
		i++;
	}
	cmd[i] = 0;
	return (cmd);
}

char	**split_process(char *line)
{
	char	**cmd_line;
	int		count;
	int		i;

	count = count_cmd_line(line);
	cmd_line = (char **)malloc(sizeof(char *) * (count + 1));
	if (!cmd_line)
		return (0);
	i = 0;
	while (*line)
	{
		if (*line && (is_special_symbol(*line) != T_NONE))
		{
			add_last(token, put_cmd_line(line, is_special_symbol(*line), is_special_symbol(*line)))
			i++;
		}
		while (*line && (is_special_symbol(*line) != T_NONE))
			line++;
		if (*line && (is_special_symbol(*line) == T_NONE))
		{
			cmd_line[i] = put_cmd_line(line, is_special_symbol(*line));
			// if (cmd_line[i] == 0)
			// 	return (ft_free2(cmd_line));
			i++;
		}
		while (*line && (is_special_symbol(*line) == T_NONE))
			line++;
	}
	cmd_line[i] = 0;
	return (cmd_line);
}

int main(int ac, char **av, char **envp)
{
	char	*line;
	char	**strs;

	ac = 0;
	av = NULL;
	envp = NULL;
	while (1)
	{
		line = readline("minishell$ ");
		strs = split_process(line);
		int i = 0;
		while (strs[i])
		{
			printf("%s\n", strs[i]);
			i++;
		}
		free(line);
	}
}

