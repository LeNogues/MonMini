/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:36:01 by seb               #+#    #+#             */
/*   Updated: 2025/06/05 20:47:26 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

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

void	get_rid_slash(char *cwd)
{
	int	i;

	i = 0;
	while (cwd[i])
		i++;
	if (cwd[i - 1] == '/')
		cwd[i - 1] = 0;
}

char	*case_root(char *cwd, char **temp)
{
	if (ft_strncmp(cwd, "/", 2) != 0)
	{
		*temp = ft_strjoin(cwd, "/");
		if (!temp)
			return (free(cwd), NULL);
	}
	else
	{
		*temp = ft_strdup(cwd);
		if (!*temp)
			return (free(cwd), NULL);
	}
	return (*temp);
}

char	*create_new_path(t_env *env, char *path)
{
	char	*cwd;
	char	*temp;

	temp = NULL;
	cwd = ft_getenv("PWD=", env);
	if (!cwd)
		return (perror("ft_getenv"), NULL);
	if (ft_strncmp(cwd, "/", 2) != 0 || path)
		temp = case_root(cwd, &temp);
	if (temp)
	{
		free(cwd);
		cwd = ft_strjoin(temp, path);
	}
	else
		return (NULL);
	if (!cwd)
		return (free(temp), free(path), perror("ft_strjoin"), NULL);
	free(path);
	free(temp);
	path = ft_strdup(cwd);
	if (!path)
		return (free(cwd), perror("ft_strdup"), NULL);
	free(cwd);
	return (path);
}
