/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:39:42 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/05/05 15:17:13 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	syntax_verif(t_token **head)
{
	t_token	*current;

	current = *head;
	if (current == NULL || current->type == PIPE)
		return (printf("ERROR\n"), 1);
	while (current)
	{
		if (is_redir_type(current->type))
		{
			if (handle_redir_syntax(&current))
				return (1);
		}
		else if (current->type == PIPE)
		{
			if (handle_pipe_syntax(&current))
				return (1);
		}
		else if (current->type == ERROR)
			return (printf("ERROR\n"), 1);
		else
			current = current->next;
	}
	return (0);
}
