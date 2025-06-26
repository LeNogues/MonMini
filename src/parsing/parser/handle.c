/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:30:23 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/25 16:43:42 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

t_token	*handle_cmd_token(t_cmd *node, t_token *token, int *i)
{
	if (token->type == COMMAND || token->type == STRING
		|| token->type == EXPAND || token->type == RETURN_COMMAND)
	{
		node->cmd[*i] = ft_strndup(token->start, token->length);
		if (!node->cmd[*i])
			return (NULL);
		(*i)++;
	}
	return (token);
}

t_token	*handle_redir_in(t_cmd *node, t_token *token, int *r)
{
	token = token->next;
	while (token && token->type == WHITESPACE)
		token = token->next;
	if (token)
	{
		node->name[*r] = ft_strndup(token->start, token->length);
		if (!node->name[*r])
			return (NULL);
		node->in_or_out[*r] = 1;
	}
	(*r)++;
	return (token);
}

t_token	*handle_redir_out(t_cmd *node, t_token *token, int *r)
{
	int	type;

	if (token->type == APPEND)
		type = 3;
	else
		type = 2;
	token = token->next;
	while (token && token->type == WHITESPACE)
		token = token->next;
	if (token)
	{
		node->name[*r] = ft_strndup(token->start, token->length);
		if (!node->name[*r])
			return (NULL);
		node->in_or_out[*r] = type;
	}
	(*r)++;
	return (token);
}

t_token	*handle_heredoc(t_cmd *node, t_token *token, int *r)
{
	token = token->next;
	while (token && token->type == WHITESPACE)
		token = token->next;
	if (token)
	{
		if (node->heredoc == 0)
			node->heredoc = 1;
		else
			node->heredoc++;
		node->name[*r] = ft_strndup(token->start, token->length);
		if (!node->name[*r])
			return (NULL);
		node->in_or_out[*r] = 4;
	}
	(*r)++;
	return (token);
}
