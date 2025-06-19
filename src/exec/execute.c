/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:55:46 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 21:55:06 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	execute(t_info *info, t_env *env, t_pipe *pipe_fd)
{
	info->cmd->full_path = verif_arg(info, pipe_fd, env);
	if (!info->cmd->cmd)
		free_cmd_env_pipe(info, env, pipe_fd);
	if (info->cmd->full_path)
		execve(info->cmd->full_path, info->cmd->cmd, env->envp);
	write(2, "execution impossible\n", 21);
	free_cmd_env_pipe(info, env, pipe_fd);
}
