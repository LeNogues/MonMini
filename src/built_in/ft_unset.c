/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:46:43 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/20 19:49:39 by sle-nogu         ###   ########.fr       */
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

static int	count_vars_to_keep(char **current_envp, char **cmd_args)
{
	int	i;
	int	keep_count;

	i = 0;
	keep_count = 0;
	while (current_envp[i])
	{
		if (!is_var_to_unset(current_envp[i], cmd_args))
			keep_count++;
		i++;
	}
	return (keep_count);
}

static int	populate_new_env(char **new_envp, char **old_envp, char **cmd_args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old_envp[i])
	{
		if (!is_var_to_unset(old_envp[i], cmd_args))
		{
			new_envp[j] = ft_strdup(old_envp[i]);
			if (!new_envp[j])
			{
				free_tab(new_envp);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **cmd, t_env *env)
{
	int		keep_count;
	char	**new_envp;

	if (!cmd[1] || !env || !env->envp)
		return (0);
	keep_count = count_vars_to_keep(env->envp, cmd);
	new_envp = ft_calloc(keep_count + 1, sizeof(char *));
	if (!new_envp)
		return (1);
	if (populate_new_env(new_envp, env->envp, cmd))
		return (1);
	free_tab(env->envp);
	env->envp = new_envp;
	return (0);
}
