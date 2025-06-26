/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:58:32 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/19 16:10:16 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	insert_at_head(t_token **head, t_token *token)
{
	token->next = *head;
	*head = token;
}

void	insert_last(t_token **head, t_token *token_list)
{
	t_token	*parcours;

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

int	create_list_of_token(t_token **head)
{
	int		j;
	t_token	token;
	t_token	*token_list;

	j = 0;
	while (!is_at_end())
	{
		token = scan_one_token();
		token_list = malloc(sizeof(t_token));
		if (!token_list)
			return (0);
		token_list->start = ft_strndup(token.start, token.length);
		if (!token_list->start)
			return (0);
		token_list->length = token.length;
		token_list->type = token.type;
		token_list->next = NULL;
		insert_last(head, token_list);
		j++;
	}
	return (j);
}

void	exit_and_free_clean(t_token **head, t_info *info)
{
	free_tab(info->env->envp);
	free(info->env);
	free(info);
	free_token_list(head);
	exit(1);
}
