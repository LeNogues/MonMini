/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:32:00 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/27 22:59:26 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	set_environment(t_info *info, t_env *env, char **envp)
{
	int			i;
	const int	size = ft_tablen(envp) + 1;

	i = 0;
	if (!info->env || !envp)
		return (1);
	env->envp = ft_calloc(sizeof(char *), size);
	if (!env->envp)
		return (-1);
	while (envp[i])
	{
		env->envp[i] = ft_strdup(envp[i]);
		if (!env->envp[i])
			return (7);
		i++;
	}
	env->envp[i] = NULL;
	return (0);
}

int	create_env(t_env *env)
{
	env->envp = malloc(sizeof(char *) * 2);
	if (!env->envp)
		return (-1);
	env->envp[0] = ft_strjoin(ft_strdup("PWD="), getcwd(NULL, 0));
	if (!env->envp[0])
		return (free(env->envp), -1);
	env->envp[1] = 0;
	return (0);
}
