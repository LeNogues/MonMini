/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:33:01 by oettaqi           #+#    #+#             */
/*   Updated: 2025/06/27 14:39:45 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

t_token	scan_one_token(void)
{
	char	*pos;
	int		nbr;
	char	c;
	t_token	lessgo;

	pos = skip_white();
	nbr = (int)(scanner()->current - pos);
	if (nbr >= 1)
	{
		scanner()->start = pos;
		return (make_token(WHITESPACE));
	}
	scanner()->start = scanner()->current;
	c = advance();
	lessgo = create_single_token(c);
	if (lessgo.type != NONE)
		return (lessgo);
	while (!is_at_end() && !is_sep(peek()))
		advance();
	return (make_token(COMMAND));
}

const char	*type_to_str(t_token_type type)
{
	if (type == COMMAND)
		return ("COMMAND");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == REDIR_IN)
		return ("REDIR_IN");
	else if (type == REDIR_OUT)
		return ("REDIR_OUT");
	else if (type == HEREDOC)
		return ("HEREDOC");
	else if (type == APPEND)
		return ("APPEND");
	else if (type == EMPTY_STRING)
		return ("EMPTY_STRING");
	else if (type == ERROR)
		return ("ERROR");
	else if (type == EXPAND)
		return ("EXPAND");
	else if (type == WHITESPACE)
		return ("WHITESPACE");
	else if (type == STRING)
		return ("STRING");
	return ("ERROR");
}

void	free_all(t_token **head)
{
	t_token	*parcours;
	t_token	*tmp;

	parcours = *head;
	while (parcours)
	{
		tmp = parcours->next;
		free(parcours);
		parcours = tmp;
	}
	*head = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_cmd	*merge(t_info *info, char *source)
{
	t_token	*head;
	t_cmd	*final;

	(void)info;
	init_scanner(source);
	head = NULL;
	final = NULL;
	if (create_list_of_token(&head) == 0)
	{
		free(source);
		free_tab(info->env->envp);
		free(info->env);
		free(info);
		exit(1);
	}
	expand_token(&head, info);
	fusion(&head, info);
	parser(&head, &final, info);
	ft_list_len(final);
	free_token_list(&head);
	return (final);
}
