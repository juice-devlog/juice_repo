/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:29:40 by jooypark          #+#    #+#             */
/*   Updated: 2023/10/09 22:58:56 by jooypark         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define T_NONE 0
# define T_ARG 1
# define T_PIPE 2
# define T_LEFT_REDIR 3
# define T_RIGHT_REDIR 4
# define T_LEFT_DREDIR 5
# define T_RIGHT_DREDIR 6
# define T_AMPERSAND 7
# define T_COLON 8
# define T_SEP 9

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*next;
}	t_token;

#endif