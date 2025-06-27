/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:37:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/27 11:17:14 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	prepare_redirections(t_info *info)
{
	int	i;
	int	result;

	info->cmd->fd_in = STDIN_FILENO;
	info->cmd->fd_out = STDOUT_FILENO;
	if (!info->cmd->name)
		return (1);
	i = 0;
	while (info->cmd->name[i])
	{
		printf("%s\n", info->cmd->name[1]);
		result = open_all(info, i);
		if (result > 0)
		{
			if (info->cmd->fd_in > STDIN_FILENO)
				close(info->cmd->fd_in);
			if (info->cmd->fd_out > STDOUT_FILENO)
				close(info->cmd->fd_out);
			return (0);
		}
		i++;
	}
	return (1);
}

void	close_redirection_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
}

void	open_and_execute(t_info *info, t_pipe *pipe_fd)
{
	int	result;

	signal(SIGINT, ctrl_c);
	dup_no_fd(info->cmd, pipe_fd);
	close_redirection_fds(info->cmd);
	result = choice_of_builtin(info, info->env, pipe_fd);
	if (result == -1)
		execute(info, info->env, pipe_fd);
	else
		exit_clean(result, info, info->env, pipe_fd);
}

void	handle_cmd(t_info *info, t_pipe *pipe_fd)
{
	if (!prepare_redirections(info))
	{
		if (info->return_value != 130)
			info->return_value = 1;
		return ;
	}
	if (info->cmd->cmd)
	{
		execute_or_fork(info, pipe_fd);
		if (info->cmd->nb_cmd == 1)
			close_pipe_fd(pipe_fd->old);
	}
	close_redirection_fds(info->cmd);
}
