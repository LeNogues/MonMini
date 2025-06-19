/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:14:04 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/04/02 17:36:47 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	*get_path(t_env *env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env->envp[i])
	{
		if (ft_strncmp(env->envp[i], "PATH=", 5) == 0)
		{
			path = malloc(ft_strlen(env->envp[i]) + 1);
			if (path == NULL)
				return (0);
			ft_strlcpy(path, env->envp[i] + 5, ft_strlen(env->envp[i]) - 4);
			break ;
		}
		i++;
	}
	return (path);
}
