/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:37:51 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 22:53:07 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int			g_state_signal = 1;

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	(void)argc;
	(void)argv;
	info = calloc(1, sizeof(t_info));
	if (!info)
		return (0);
	info->env = malloc(sizeof(t_env));
	if (!info->env)
		return (free(info), 0);
	handle_signal();
	if (!info->env)
		return (-1);
	if (!envp[0])
	{
		if (create_env(info->env))
			return (free(info), -1);
	}
	else if (set_environment(info->env, envp))
		return (free(info->env), free(info), -1);
	hub(info);
	free_tab(info->env->envp);
	free(info->env);
	free(info);
	return (0);
}
