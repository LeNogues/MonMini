/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:04:03 by oettaqi           #+#    #+#             */
/*   Updated: 2025/05/30 15:31:22 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

t_token	make_token(t_token_type type)
{
	t_token	token;

	token.type = type;
	token.start = scanner()->start;
	if (type == EMPTY_STRING)
	{
		token.length = (int)(scanner()->current - scanner()->start + 1);
		return (token);
	}
	token.length = (int)(scanner()->current - scanner()->start);
	return (token);
}

t_token	string(char quote)
{
	while (peek() != quote && !is_at_end())
		advance();
	if (is_at_end())
		return (make_token(ERROR));
	advance();
	return (make_token(STRING));
}

t_token	expand(void)
{
	if (peek() == '?')
	{
		advance();
		return (make_token(RETURN_COMMAND));
	}
	while (!is_at_end() && (is_allnum(peek()) || peek() == '_'))
		advance();
	return (make_token(EXPAND));
}

char	*skip_white(void)
{
	char	*pos;

	pos = scanner()->current;
	while (is_space(peek()))
		advance();
	return (pos);
}
