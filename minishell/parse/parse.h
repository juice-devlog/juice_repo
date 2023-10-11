/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:29:40 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/11 21:35:31 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define T_NONE 0
# define T_ARG 1
# define T_PIPE 2
# define T_REDIR 3
# define T_LIMITER 4
# define T_SQUOTE 5
# define T_DQUOTE 6

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*next;
}	t_token;

void	parse_heredoc_limiter(t_token *token);
void	tokenize(t_token *token, char *line, char **envp);
int	check_quote(char *cmd_line);
char	*create_new_str(char *target, int start, int end);
void	parse_quote(t_token *token);
void	insert(t_token *prev_token, char *new_str, int new_type);

#endif