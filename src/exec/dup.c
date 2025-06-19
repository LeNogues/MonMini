/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:59 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/19 12:19:39 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	dup_no_fd(t_cmd *cmd, t_pipe *pipe_fd)
{
	if (cmd->pos == 1)
		dup_first(cmd, pipe_fd);
	if (cmd->pos == 2)
		dup_middle(cmd, pipe_fd);
	if (cmd->pos == 3)
		dup_last(cmd, pipe_fd);
}

int	dup_first(t_cmd *cmd, t_pipe *pipe_fd)
{
	if (cmd->fd_in != STDIN_FILENO)
		if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
			return (0);
	if (cmd->fd_out != STDOUT_FILENO)
	{
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
			return (0);
	}
	else if (cmd->nb_cmd > 1)
	{
		if (dup2(pipe_fd->old[1], STDOUT_FILENO) == -1)
			return (0);
	}
	close_pipe_fd(pipe_fd->old);
	return (1);
}

int	dup_middle(t_cmd *cmd, t_pipe *pipe_fd)
{
	if (cmd->fd_in != STDIN_FILENO)
	{
		if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
			return (0);
	}
	else
	{
		if (dup2(pipe_fd->old[0], STDIN_FILENO) == -1)
			return (0);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
			return (0);
	}
	else
	{
		if (dup2(pipe_fd->new[1], STDOUT_FILENO) == -1)
			return (0);
	}
	close_pipe_fd(pipe_fd->old);
	close_pipe_fd(pipe_fd->new);
	return (1);
}

int	dup_last(t_cmd *cmd, t_pipe *pipe_fd)
{
	if (cmd->fd_in != STDIN_FILENO)
	{
		if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
			return (0);
	}
	else
	{
		if (dup2(pipe_fd->old[0], STDIN_FILENO) == -1)
			return (0);
	}
	if (cmd->fd_out != STDOUT_FILENO)
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
			return (0);
	close_pipe_fd(pipe_fd->old);
	return (1);
}
