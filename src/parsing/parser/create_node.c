/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:30:17 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/27 15:22:44 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	finalize_node(t_cmd *node, int cmd_count, int redir_count)
{
	node->cmd[cmd_count] = NULL;
	node->name[redir_count] = NULL;
	if (node->cmd[0] == NULL)
	{
		free(node->cmd);
		node->cmd = NULL;
	}
	if (node->name[0] == NULL)
	{
		free(node->name);
		free(node->in_or_out);
		node->name = NULL;
		node->in_or_out = NULL;
	}
}

void	count(t_token *start, t_token *pipe, int *cmd_size, int *redir_size)
{
	t_token	*parcours;

	*cmd_size = 0;
	*redir_size = 0;
	parcours = start;
	while (parcours != pipe)
	{
		if (parcours->type == COMMAND || parcours->type == STRING
			|| parcours->type == EXPAND || parcours->type == RETURN_COMMAND)
			(*cmd_size)++;
		else if (parcours->type == REDIR_IN || parcours->type == REDIR_OUT
			|| parcours->type == APPEND || parcours->type == HEREDOC)
			(*redir_size)++;
		parcours = parcours->next;
	}
}

int	fill(t_cmd *node, t_token *start, t_token *pipe, int indices[2])
{
	t_token	*parcours;

	parcours = start;
	while (parcours != pipe)
	{
		if (parcours->type == COMMAND || parcours->type == STRING
			|| parcours->type == EXPAND || parcours->type == RETURN_COMMAND)
			parcours = handle_cmd_token(node, parcours, &indices[0]);
		else if (parcours->type == REDIR_IN)
			parcours = handle_redir_in(node, parcours, &indices[1]);
		else if (parcours->type == REDIR_OUT || parcours->type == APPEND)
			parcours = handle_redir_out(node, parcours, &indices[1]);
		else if (parcours->type == HEREDOC)
			parcours = handle_heredoc(node, parcours, &indices[1]);
		if (parcours == NULL)
			return (0);
		parcours = parcours->next;
	}
	return (1);
}

t_cmd	*create_one_node(t_token *start, t_token *pipe)
{
	t_cmd	*node;
	int		indices[2];
	int		cmd_size;
	int		redir_size;

	count(start, pipe, &cmd_size, &redir_size);
	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	if (initialise_node(&node, cmd_size, redir_size) == 0)
		return (free(node), NULL);
	init_indices(indices);
	if (fill(node, start, pipe, indices) == 0)
		return (NULL);
	finalize_node(node, indices[0], indices[1]);
	return (node);
}
