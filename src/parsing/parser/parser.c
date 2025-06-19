/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:27:06 by taqi              #+#    #+#             */
/*   Updated: 2025/06/19 15:23:33 by sle-nogu         ###   ########.fr       */
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

void	parser(t_token **head, t_cmd **final)
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
			node = create_one_node(current_start, current);
			insert_last_tcmd(final, node);
			current_start = current->next;
			current = current_start;
		}
		current = current->next;
	}
	if (current_start)
	{
		node = create_one_node(current_start, NULL);
		if (node)
			insert_last_tcmd(final, node);
	}
}
