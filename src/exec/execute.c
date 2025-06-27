/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:55:46 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/27 11:21:05 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	fork_and_execute_cmd(t_info *info, t_pipe *pipe_fd)
{
	int	id;

	handle_signal_bis();
	id = fork();
	g_state_signal = 2;
	if (id == 0)
		open_and_execute(info, pipe_fd);
	return (id);
}

void	execute_or_fork(t_info *info, t_pipe *pipe_fd)
{
	int	type;

	type = get_type(info);
	if (type != 0 && info->cmd->nb_cmd == 1 && is_parent_builtin(type))
		info->return_value = execute_parent_builtin(type, info, info->env);
	else
		info->last_pid = fork_and_execute_cmd(info, pipe_fd);
}

void	execute(t_info *info, t_env *env, t_pipe *pipe_fd)
{
	info->cmd->full_path = verif_arg(info, pipe_fd, env);
	if (!info->cmd->cmd)
		free_cmd_env_pipe(info, env, pipe_fd);
	if (info->cmd->full_path)
	{
		signal(SIGQUIT, &ctrl_back);
		execve(info->cmd->full_path, info->cmd->cmd, env->envp);
	}
	write(2, "execution impossible\n", 21);
	free_cmd_env_pipe(info, env, pipe_fd);
}
