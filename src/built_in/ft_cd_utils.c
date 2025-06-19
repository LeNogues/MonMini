/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:30:20 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 22:04:08 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	cd_home(t_env *env, char **path)
{
	char	*env_line;

	env_line = ft_getenv("HOME=", env);
	if (!env_line)
		env_line = NULL;
	*path = ft_strdup(env_line);
	if (!*path)
	{
		free(*path);
		free(env_line);
		return (write(1, "HOME not set\n", 13), 0);
	}
	free(env_line);
	return (1);
}

char	*do_something(char *temp_pwd, int last, char *old, char *new_pwd)
{
	int	i;

	i = -1;
	temp_pwd = malloc(sizeof(char) * (last) + 1);
	if (!temp_pwd)
		return (NULL);
	while (++i < last)
		temp_pwd[i] = old[i];
	temp_pwd[i] = 0;
	new_pwd = ft_strjoin("PWD=", temp_pwd);
	if (!new_pwd)
		return (free(temp_pwd), NULL);
	free(temp_pwd);
	return (new_pwd);
}

char	*join_parent(char *temp_pwd, int last, char *old, char *new_pwd)
{
	if (ft_strncmp(old, "/home", 6) == 0 || ft_strncmp(old, "/", 2) == 0)
	{
		new_pwd = ft_strjoin("PWD=", "/");
		if (!new_pwd)
			return (free(old), NULL);
	}
	else
	{
		new_pwd = do_something(temp_pwd, last, old, new_pwd);
		if (!new_pwd)
			return (free(old), NULL);
	}
	return (new_pwd);
}

char	*get_parent(t_env *env)
{
	int		last;
	int		i;
	char	*old;
	char	*temp_pwd;
	char	*new_pwd;

	i = 0;
	last = 0;
	old = ft_getenv("PWD=", env);
	temp_pwd = NULL;
	new_pwd = NULL;
	if (!old)
		return (0);
	while (old[i])
	{
		if (old[i] == '/')
			last = i;
		i++;
	}
	new_pwd = join_parent(temp_pwd, last, old, new_pwd);
	if (!new_pwd)
		return (NULL);
	free(old);
	return (new_pwd);
}
