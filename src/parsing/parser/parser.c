/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:27:06 by taqi              #+#    #+#             */
/*   Updated: 2025/06/26 11:47:45 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	initialise_node(t_cmd **node, int cmd_size, int redir_size)
{
	(*node)->cmd = malloc(sizeof(char *) * (cmd_size + 1));
	if (!(*node)->cmd)
		return (0);
	(*node)->name = malloc(sizeof(char *) * (redir_size + 1));
	if (!(*node)->name)
	{
		free((*node)->cmd);
		return (0);
	}
	(*node)->in_or_out = malloc(sizeof(int) * (redir_size + 1));
	if (!(*node)->in_or_out)
	{
		free((*node)->cmd);
		free((*node)->name);
		return (0);
	}
	(*node)->full_path = NULL;
	(*node)->heredoc = 0;
	(*node)->pos = 0;
	(*node)->fd_in = 0;
	(*node)->fd_out = 0;
	(*node)->nb_cmd = 0;
	return (1);
}

void	insert_last_tcmd(t_cmd **head, t_cmd *token_list)
{
	t_cmd	*parcours;

	parcours = *head;
	if (*head == NULL)
	{
		*head = token_list;
		token_list->next = NULL;
		return ;
	}
	while (parcours->next)
		parcours = parcours->next;
	parcours->next = token_list;
	token_list->next = NULL;
}

void	init_indices(int indices[2])
{
	indices[0] = 0;
	indices[1] = 0;
}

int	add_node_until_pipe(t_cmd **final, t_token **start, t_token *pipe)
{
	t_cmd	*node;

	node = create_one_node(*start, pipe);
	if (!node)
		return (0);
	insert_last_tcmd(final, node);
	*start = pipe->next;
	return (1);
}

void	parser(t_token **head, t_cmd **final, t_info *info)
{
	t_token	*current_start;
	t_token	*current;
	t_cmd	*node;

	if (syntax_verif(head) == 1)
		return ;
	current_start = *head;
	current = current_start;
	while (current)
	{
		if (current->type == PIPE)
		{
			if (!add_node_until_pipe(final, &current_start, current))
				exit_and_free_clean_pars(head, final, info);
			current = current_start;
		}
		current = current->next;
	}
	if (current_start)
	{
		node = create_one_node(current_start, NULL);
		if (!node)
			exit_and_free_clean_pars(head, final, info);
		insert_last_tcmd(final, node);
	}
}

// void	parser(t_token **head, t_cmd **final, t_info *info)
// {
// 	t_token	*current_start;
// 	t_token	*current;
// 	t_cmd	*node;

// 	if (syntax_verif(head) == 1)
// 		return ;
// 	current_start = *head;
// 	current = current_start;
// 	while (current)
// 	{
// 		if (current->type == PIPE)
// 		{
// 			node = create_one_node(current_start, current);
// 			insert_last_tcmd(final, node);
// 			current_start = current->next;
// 			current = current_start;
// 		}
// 		current = current->next;
// 	}
// 	if (current_start)
// 	{
// 		node = create_one_node(current_start, NULL);
// 		if (!node)
// 			exit_and_free_clean_pars(head, final, info);
// 		if (node)
// 			insert_last_tcmd(final, node);
// 	}
// }
