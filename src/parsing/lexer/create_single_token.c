/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:27:16 by seb               #+#    #+#             */
/*   Updated: 2025/06/20 13:03:06 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

t_token	create_single_token(char c)
{
	if (c == '|' )
		return (make_token(PIPE));
	else if (c == '<' && peek() != '<')
		return (make_token(REDIR_IN));
	else if (c == '>' && peek() != '>')
		return (make_token(REDIR_OUT));
	else if (c == '<' && peek() == '<')
	{
		if (peek_next() == '<')
			return (make_token(ERROR));
		advance();
		return (make_token(HEREDOC));
	}
	else if (c == '>' && peek() == '>')
	{
		if (peek_next() == '>')
			return (make_token(ERROR));
		advance();
		return (make_token(APPEND));
	}
	else if (c == '"' )
		return (string(c));
	else if (c == 39)
		return (string(39));
	else if (c == '$')
		return (expand());
	return (make_token(NONE));
}
