/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:12:07 by seb               #+#    #+#             */
/*   Updated: 2025/06/21 15:46:00 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	execute_built_in(int type, t_info *info, t_env *env, t_pipe *pipe_fd)
{
	int	result;

	if (info->cmd->nb_cmd == 1)
	{
		if (dup2(STDOUT_FILENO, info->cmd->fd_out) == -1)
			exit_clean(1, info, env, pipe_fd);
		if (dup2(STDIN_FILENO, info->cmd->fd_in) == -1)
			exit_clean(1, info, info->env, info->pipe);
		if (!verif_file_builtin(info, pipe_fd))
			return (1);
	}
	result = execute_built_in_bis(type, info, env, pipe_fd);
	if (info->cmd->nb_cmd == 1)
	{
		if (info->cmd->fd_out)
		{
			close(info->cmd->fd_out);
			if (dup2(info->cmd->fd_out, STDOUT_FILENO) == -1)
				exit_clean(1, info, info->env, info->pipe);
		}
		if (info->cmd->fd_in)
			if (dup2(info->cmd->fd_in, STDIN_FILENO) == -1)
				exit_clean(1, info, info->env, info->pipe);
	}
	return (result);
}

int	choice_of_builtin(t_info *info, t_env *env, t_pipe *pipe_fd)
{
	int	result;
	int	type;
	int	id;

	result = -1;
	type = 0;
	id = -1;
	info->cmd->fd_stdout = 0;
	info->cmd->fd_stdin = 0;
	if (!info->cmd->cmd)
		return (-1);
	type = get_type(info);
	if (type != 0)
		result = execute_built_in(type, info, env, pipe_fd);
	return (result);
}

void	hub(t_info *info)
{
	char	*line;

	info->return_value = 0;
	while (1)
	{
		g_state_signal = 1;
		signal(SIGQUIT, SIG_IGN);
		line = readline("\001\e[32m\002Minishell : \001\e[0m\002");
		if (!line)
			return ;
		if (line[0] != 0)
			add_histo_and_exec(info, line);
		if (g_state_signal == 130 || g_state_signal == 131)
			info->return_value = g_state_signal;
		free(line);
		signal(SIGINT, ctrl_c);
	}
}
