/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:48:50 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/05/06 20:36:32 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Minishell.h"

t_token	*find_next_significant(t_token *current)
{
	t_token	*next;

	next = NULL;
	if (current)
	{
		next = current->next;
		while (next != NULL && next->type == WHITESPACE)
		{
			next = next->next;
		}
	}
	return (next);
}

int	is_valid_redir_target_type(t_token_type type)
{
	return (type == COMMAND || type == EXPAND || type == STRING);
}

int	handle_redir_syntax(t_token **current_ptr)
{
	t_token	*next_significant;

	next_significant = find_next_significant(*current_ptr);
	if (next_significant == NULL || \
		!is_valid_redir_target_type(next_significant->type))
	{
		printf("ERROR\n");
		return (1);
	}
	*current_ptr = next_significant->next;
	return (0);
}

int	handle_pipe_syntax(t_token **current_ptr)
{
	t_token	*next_significant;

	next_significant = find_next_significant(*current_ptr);
	if (next_significant == NULL || next_significant->type == PIPE)
	{
		printf("ERROR\n");
		return (1);
	}
	*current_ptr = next_significant;
	return (0);
}

int	is_redir_type(t_token_type type)
{
	return (type == REDIR_IN || type == REDIR_OUT
		|| type == APPEND || type == HEREDOC);
}
