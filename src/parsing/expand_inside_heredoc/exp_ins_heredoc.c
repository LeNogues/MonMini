/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_ins_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:15:05 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/26 12:17:44 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static char	*append_char(char *s, char c)
{
	size_t	len;
	char	*new;

	if (s == NULL)
		len = 0;
	else
		len = ft_strlen(s);
	new = malloc(len + 2);
	if (new == NULL)
		return (NULL);
	if (s != NULL)
		ft_memcpy(new, s, len);
	new[len] = c;
	new[len + 1] = '\0';
	free(s);
	return (new);
}

static int	handle_status(char **out, t_info *info, size_t *i)
{
	char	*sts;
	char	*tmp;

	sts = ft_itoa(info->return_value);
	if (!sts)
		return (0);
	tmp = ft_strjoin(*out, sts);
	free(*out);
	free(sts);
	*out = tmp;
	*i += 2;
	return (1);
}

static int	handle_variable(char **out, char *line, size_t *i, t_info *info)
{
	size_t	start;
	char	*name;
	char	*val;
	char	*tmp;

	(*i)++;
	start = *i;
	while (ft_isalnum(line[*i]) || line[*i] == '_')
		(*i)++;
	name = ft_substr(line, start, *i - start);
	val = ft_getenv_bis(name, info->env);
	if (!val)
		val = "";
	tmp = ft_strjoin(*out, val);
	free(*out);
	free(name);
	free(val);
	*out = tmp;
	return (1);
}

static int	process_dollar(char **out, char *line, size_t *i, t_info *info)
{
	if (line[*i + 1] == '?')
		return (handle_status(out, info, i));
	if (!ft_isalpha(line[*i + 1]) && line[*i + 1] != '_')
	{
		*out = append_char(*out, line[(*i)++]);
		return (1);
	}
	return (handle_variable(out, line, i, info));
}

char	*expand_for_heredoc(char *line, t_info *info)
{
	size_t	i;
	char	*out;

	i = 0;
	out = ft_strdup("");
	if (!out)
		return (free(line), NULL);
	while (line && line[i])
	{
		if (line[i] == '$' && line[i + 1])
		{
			if (!process_dollar(&out, line, &i, info))
				return (free(out), free(line), NULL);
			continue ;
		}
		out = append_char(out, line[i++]);
		if (!out)
			return (free(line), NULL);
	}
	free(line);
	return (out);
}
