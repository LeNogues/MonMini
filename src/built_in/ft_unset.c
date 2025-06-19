/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:46:43 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/19 15:10:19 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static int	is_var_to_unset(const char *env_var, char **args)
{
	int		i;
	int		name_len;
	char	*equal_sign;

	equal_sign = ft_strchr(env_var, '=');
	if (!equal_sign)
		name_len = ft_strlen(env_var);
	else
		name_len = equal_sign - env_var;
	i = 1;
	while (args[i])
	{
		if ((int)ft_strlen(args[i]) == name_len)
		{
			if (ft_strncmp(env_var, args[i], name_len) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **cmd, t_env *env)
{
	int		i;
	int		j;
	int		keep_count;
	char	**new_envp;

	if (!cmd[1] || !env || !env->envp)
		return (0);
	keep_count = 0;
	i = 0;
	while (env->envp[i])
	{
		if (!is_var_to_unset(env->envp[i], cmd))
			keep_count++;
		i++;
	}
	new_envp = ft_calloc(sizeof(char *), (keep_count + 2));
	if (!new_envp)
		return (1);
	i = 0;
	j = 0;
	while (env->envp[i])
	{
		if (!is_var_to_unset(env->envp[i], cmd))
		{
			new_envp[j] = ft_strdup(env->envp[i]);
			if (!new_envp[j])
			{
				free_tab(new_envp);
				return (1);
			}
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	free_tab(env->envp);
	env->envp = new_envp;
	return (0);
}
