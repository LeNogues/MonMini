/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:27:06 by taqi              #+#    #+#             */
/*   Updated: 2025/06/20 19:51:35 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

// typedef struct s_cmd
// {
//     char            **cmd;
//     char            **name;
//     int             *in_or_out;
//     int             fd_in;
//     int             fd_out;
//     struct s_cmd    *next;
// }	t_cmd;

// grep banane < test.txt < banane.txt | wc -l >> nb_ligne.txt

void	initialise_node(t_cmd **node, int cmd_size, int redir_size)
{
	(*node)->cmd = malloc(sizeof(char *) * (cmd_size + 1));
	if (!(*node)->cmd)
		return ;
	(*node)->name = malloc(sizeof(char *) * (redir_size + 1));
	if (!(*node)->name)
		return ;
	(*node)->in_or_out = malloc(sizeof(int) * (redir_size + 1));
	if (!(*node)->in_or_out)
		return ;
	(*node)->full_path = NULL;
	(*node)->heredoc = 0;
	(*node)->pos = 0;
	(*node)->fd_in = 0;
	(*node)->fd_out = STDOUT_FILENO;
	(*node)->nb_cmd = 0;
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

static t_token	*process_pipe_segments(t_cmd **cmd_list, t_token *token)
{
	t_token	*segment_start;
	t_token	*current_token;
	t_cmd	*node;

	segment_start = token;
	current_token = token;
	while (current_token)
	{
		if (current_token->type == PIPE)
		{
			node = create_one_node(segment_start, current_token);
			insert_last_tcmd(cmd_list, node);
			segment_start = current_token->next;
		}
		current_token = current_token->next;
	}
	return (segment_start);
}

int	parser(t_token **head, t_cmd **final)
{
	t_token	*last_segment_start;
	t_cmd	*node;

	if (syntax_verif(head) == 1)
		return (2);
	last_segment_start = process_pipe_segments(final, *head);
	if (last_segment_start)
	{
		node = create_one_node(last_segment_start, NULL);
		if (node)
			insert_last_tcmd(final, node);
	}
	return (0);
}
