/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:46:15 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/19 16:19:58 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	ft_env(t_env *env)
{
	int	i;

	i = 0;
	if (!env || !env->envp)
		return (126);
	while (env->envp[i])
	{
		if (ft_strlen(env->envp[i++]) > 2097152)
		{
			printf("Argument list too long");
			return (126);
		}
	}
	i = 0;
	while (env->envp[i])
		printf("%s\n", env->envp[i++]);
	return (0);
}
