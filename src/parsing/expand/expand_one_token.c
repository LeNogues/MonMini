/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_one_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:33:32 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/27 12:05:29 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static char	*create_env_key_or_exit(t_token *token_node,
	t_token **head, t_info *info)
{
	char	*key;
	int		key_len;
	int		i;

	key_len = token_node->length - 1;
	key = malloc(sizeof(char) * (key_len + 2));
	if (!key)
		exit_and_free_clean(head, info);
	i = 0;
	while (i < key_len)
	{
		key[i] = token_node->start[i + 1];
		i++;
	}
	key[i++] = '=';
	key[i] = '\0';
	return (key);
}

static void	update_token_value_or_exit(t_token *token_node, char *value,
										t_token **head, t_info *info)
{
	free(token_node->start);
	if (!value)
	{
		token_node->start = ft_strdup("");
		if (!token_node->start)
			exit_and_free_clean(head, info);
		token_node->length = 0;
		return ;
	}
	token_node->start = ft_strdup(value);
	free(value);
	if (!token_node->start)
		exit_and_free_clean(head, info);
	token_node->length = ft_strlen(token_node->start);
}

void	expand_one_token(t_token *token_node, t_info *info, t_token **head)
{
	char	*key;
	char	*value;

	key = create_env_key_or_exit(token_node, head, info);
	if (!key)
		printf("ici?\n");
	value = ft_getenv(key, info->env);
	free(key);
	update_token_value_or_exit(token_node, value, head, info);
}
