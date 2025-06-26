/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_one_tok_for_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:30:22 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/26 11:49:27 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static char	*create_env_key(t_token *token_node)
{
	char	*key;
	int		i;
	int		j;

	i = 0;
	j = 1;
	key = malloc(sizeof(char) * (token_node->length + 1));
	if (!key)
		return (NULL);
	while (i < (token_node->length - 1))
	{
		key[i] = token_node->start[j];
		i++;
		j++;
	}
	key[i++] = '=';
	key[i] = '\0';
	return (key);
}

static int	update_token_with_value(t_token *token_node, char *value)
{
	free(token_node->start);
	if (!value)
	{
		token_node->start = ft_strdup("");
		token_node->length = 0;
		if (!token_node->start)
			return (0);
		return (3);
	}
	token_node->start = ft_strdup(value);
	free(value);
	if (!token_node->start)
		return (0);
	token_node->length = ft_strlen(token_node->start);
	return (1);
}

int	expand_one_token_for_sub(t_token *token_node, t_info *info)
{
	char	*key;
	char	*value;

	key = create_env_key(token_node);
	if (!key)
		return (0);
	value = ft_getenv(key, info->env);
	free(key);
	return (update_token_with_value(token_node, value));
}
