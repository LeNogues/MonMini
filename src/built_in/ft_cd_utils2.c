/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:36:01 by seb               #+#    #+#             */
/*   Updated: 2025/06/20 21:41:34 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static void	free_things(t_env *env, char *path, char *tmp_path, int i)
{
	free(env->envp[i]);
	free(path);
	free(tmp_path);
}

int	create_env_cd(char *env_to_create, t_env *env)
{
	char	**cmd;

	cmd = ft_split(env_to_create, ' ');
	if (!cmd)
		return (0);
	ft_export(cmd, env);
	free_tab(cmd);
	return (1);
}

void	change_pwd(t_env *env, char *path)
{
	int		i;
	char	*tmp_path;

	tmp_path = ft_strdup(path);
	if (!tmp_path)
		return ;
	if (!env || !env->envp)
	{
		free(tmp_path);
		return ;
	}
	i = find_pwd_line_index(env->envp);
	free_things(env, path, tmp_path, i);
	set_new_pwd_value(env, i);
}

void	change_old_pwd(t_env *env)
{
	char	*cwd;
	char	*old_pwd;
	int		i;

	i = 0;
	if (!env || !env->envp)
		return ;
	while (env->envp[i])
	{
		if (ft_strncmp("OLDPWD=", env->envp[i], 7) == 0)
			break ;
		i++;
	}
	if (!env->envp[i])
		if (!create_env_cd("export OLDPWD=", env))
			return ;
	cwd = ft_getenv("PWD=", env);
	if (!cwd)
		return ;
	old_pwd = ft_strjoin("OLDPWD=", cwd);
	if (!old_pwd)
		return (perror("ft_strjoin"));
	free(env->envp[i]);
	free(cwd);
	env->envp[i] = old_pwd;
}
