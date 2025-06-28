/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:39:42 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/28 04:08:28 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	syntax_verif(t_info *info, t_token **head)
{
	t_token	*current;

	current = *head;
	if (current == NULL || current->type == PIPE)
		return (printf("SYNTAX ERROR\n"), set_return(info), 1);
	while (current)
	{
		if (is_redir_type(current->type))
		{
			if (handle_redir_syntax(&current))
				return (set_return(info), 1);
		}
		else if (current->type == PIPE)
		{
			if (handle_pipe_syntax(&current))
				return (set_return(info), 1);
		}
		else if (current->type == ERROR)
			return (printf("SYNTAX ERROR\n"), set_return(info), 1);
		else
			current = current->next;
	}
	return (0);
}
