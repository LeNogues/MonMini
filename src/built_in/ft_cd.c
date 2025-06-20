/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:43:35 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/20 21:41:37 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	find_pwd_line_index(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (-1);
	while (envp[i])
	{
		if (ft_strncmp("PWD=", envp[i], 4) == 0)
			break ;
		i++;
	}
	return (i);
}

void	set_new_pwd_value(t_env *env, int index)
{
	char	*tmp_path;
	char	*cwd;

	tmp_path = ft_strdup("PWD=");
	cwd = getcwd(NULL, 0);
	if (!tmp_path || !cwd)
	{
		free(tmp_path);
		free(cwd);
		return ;
	}
	env->envp[index] = ft_strjoin(tmp_path, cwd);
	if (!env->envp)
	{
		free(tmp_path);
		free(cwd);
		return ;
	}
	free(tmp_path);
	free(cwd);
}

void	add_pwd(t_env *env)
{
	char	**cmd;

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
