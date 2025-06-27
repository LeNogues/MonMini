/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:12:07 by seb               #+#    #+#             */
/*   Updated: 2025/06/27 14:44:52 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static void	add_arguments(int i, int size, char **cmd, t_env *new_env)
{
	int	j;

	j = 1;
	while (i < size - 1 && cmd[j])
	{
		if (is_valid(cmd[j]))
		{
			if (!env_exist(new_env, cmd[j]))
			{
				new_env->envp[i] = ft_strdup(cmd[j]);
				if (!new_env->envp[i])
				{
					free_tab(new_env->envp);
					free(new_env);
					return ;
				}
				i++;
			}
		}
		j++;
	}
	new_env->envp[i] = NULL;
}

static t_env	*copy_env(t_env *env, int *i, t_env *new_env)
{
	while (env->envp[*i] != 0)
	{
		new_env->envp[*i] = ft_strdup(env->envp[*i]);
		if (!new_env->envp[*i])
		{
			free_tab(new_env->envp);
			return (0);
		}
		(*i)++;
	}
	return (new_env);
}

static t_env	*initialize_export_env(t_env *env, char **cmd)
{
	int		size;
	t_env	*new_env;

	if (!env || !env->envp)
		return (NULL);
	size = ft_tablen(env->envp) + ft_tablen(cmd) + 1;
	new_env = malloc(sizeof(t_env));
	if (!new_env)
		return (NULL);
	new_env->envp = ft_calloc(sizeof(char *), size);
	if (!new_env->envp)
	{
		free(new_env);
		return (NULL);
	}
	return (new_env);
}

static int	finalize_export(t_info *info, t_env *env, t_env *new_env)
{
	int	status;

	free_tab(env->envp);
	status = set_environment(info, env, new_env->envp);
	free_tab(new_env->envp);
	free(new_env);
	if (status == 7)
		return (7);
	return (0);
}

int	ft_export(t_info *info, char **cmd, t_env *env)
{
	int		i;
	int		size;
	t_env	*new_env;

	new_env = initialize_export_env(env, cmd);
	if (!new_env)
		return (0);
	i = 0;
	size = ft_tablen(env->envp) + ft_tablen(cmd) + 1;
	if (!copy_env(env, &i, new_env))
	{
		free_tab(new_env->envp);
		free(new_env);
		return (0);
	}
	add_arguments(i, size, cmd, new_env);
	return (finalize_export(info, env, new_env));
}
