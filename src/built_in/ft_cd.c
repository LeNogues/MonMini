/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:43:35 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/19 15:08:44 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static void	free_things(t_env *env, char *path, char *tmp_path, int i)
{
	free(env->envp[i]);
	free(path);
	free(tmp_path);
}

static void	change_pwd(t_env *env, char *path)
{
	int		i;
	char	*tmp_path;
	char	*cwd;

	i = 0;
	tmp_path = ft_strdup(path);
	if (!tmp_path)
		return ;
	if (!env || !env->envp)
		return ;
	while (env->envp[i])
	{
		if (ft_strncmp("PWD=", env->envp[i], 4) == 0)
			break ;
		i++;
	}
	free_things(env, path, tmp_path, i);
	tmp_path = ft_strdup("PWD=");
	cwd = getcwd(NULL, 0);
	if (!tmp_path || ! cwd)
		return ;
	env->envp[i] = ft_strjoin(tmp_path, cwd);
	if (!env->envp)
		return ;
	free(tmp_path);
	free(cwd);
}

static void	change_old_pwd(t_env *env)
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
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return ;
	old_pwd = ft_strjoin("OLDPWD=", cwd);
	if (!old_pwd)
		return (perror("ft_strjoin"));
	free(env->envp[i]);
	free(cwd);
	env->envp[i] = old_pwd;
}


void add_pwd(t_env  *env)
{
	char **cmd;

	cmd = ft_calloc(sizeof(char *), 2);
	cmd[0] = "PWD=";
	cmd[1] = getcwd(NULL, 0);
	ft_export(cmd, env);
}


int	ft_cd(char **cmd, t_env *env)
{
	char		*path;
	const int	size_tab = ft_tablen(cmd);

	path = NULL;
	if (size_tab == 1)
	{
		if (!cd_home(env, &path))
			return (1);
	}
	else if (size_tab > 2)
		return (perror("too many arguments"), 0);
	else
	{
		if (path)
			free(path);
		path = ft_strdup(cmd[1]);
	}
	if (chdir(path) == -1)
		return (perror(path), free(path), 1);
	change_old_pwd(env);
	change_pwd(env, path);
	return (0);
}
