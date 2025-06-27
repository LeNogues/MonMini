/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:12:07 by seb               #+#    #+#             */
/*   Updated: 2025/06/27 14:44:25 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static int	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" is invalid\n", 2);
	return (0);
}

int	env_exist(t_env *env, char *cmd)
{
	int	i;
	int	j;

	if (!env->envp || !env->envp[0] || !cmd)
		return (0);
	i = 0;
	while (env->envp[i])
	{
		j = 0;
		while (env->envp[i][j] || cmd[j])
		{
			if (env->envp[i][j] == '=' && cmd[j] == '=')
			{
				free(env->envp[i]);
				env->envp[i] = ft_strdup(cmd);
				return (1);
			}
			if (env->envp[i][j] != cmd[j])
				break ;
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (error_message(str));
	if (!strchr(str, '='))
		return (0);
	if (ft_isdigit(str[0]))
		return (error_message(str));
	while (str[i])
	{
		if (str[i] == '=' )
			return (1);
		if (str[i] != '_' && !ft_isalnum(str[i])
			&& str[i] != '=' && str[i] != ' ')
			return (error_message(str));
		i++;
	}
	return (1);
}
