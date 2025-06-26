/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:27:16 by seb               #+#    #+#             */
/*   Updated: 2025/05/06 20:27:36 by seb              ###   ########.fr       */
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
	else if (c == '<' && peek() == '<' && peek_next() != '<')
	{
		advance();
		return (make_token(HEREDOC));
	}
	else if (c == '>' && peek() == '>' && peek_next() != '>')
	{
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
