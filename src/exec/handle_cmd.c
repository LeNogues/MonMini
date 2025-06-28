/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:37:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/28 10:05:19 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	cleanup_fds_on_error(t_cmd *cmd_list)
{
	t_cmd	*current;

	current = cmd_list;
	while (current)
	{
		if (current->fd_in > 2)
			close(current->fd_in);
		if (current->fd_out > 2)
			close(current->fd_out);
		current = current->next;
	}
}

void	close_redirection_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
}

void	close_fds_in_child(t_info *info, t_cmd *current_cmd)
{
	t_cmd	*temp;

	temp = info->cmd_origin;
	while (temp)
	{
		if (temp != current_cmd)
		{
			if (temp->fd_in > 2)
				close(temp->fd_in);
			if (temp->fd_out > 2)
				close(temp->fd_out);
		}
		temp = temp->next;
	}
}

void	open_and_execute(t_info *info, t_pipe *pipe_fd)
{
	int	result;

	close_fds_in_child(info, info->cmd);
	signal(SIGINT, ctrl_c);
	dup_no_fd(info->cmd, pipe_fd);
	if (info->cmd->nb_cmd >= 3 && info->cmd != info->cmd_origin)
	{
		close(pipe_fd->new[0]);
		close(pipe_fd->new[1]);
	}
	close_redirection_fds(info->cmd);
	result = choice_of_builtin(info, info->env, pipe_fd);
	if (result == -1)
		execute(info, info->env, pipe_fd);
	else
		exit_clean(result, info, info->env, pipe_fd);
}

void	handle_cmd(t_info *info, t_pipe *pipe_fd)
{
	if (info->cmd->cmd && info->cmd->redir_error == 0)
	{
		execute_or_fork(info, pipe_fd);
	}
	close_redirection_fds(info->cmd);
	if (info->cmd->nb_cmd == 1)
		close_pipe_fd(pipe_fd->old);
}
