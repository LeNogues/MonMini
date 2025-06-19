/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:22:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/04/29 16:20:37 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	dup_fd_out(t_cmd *cmd)
{
	if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
		return (0);
	close(cmd->fd_out);
	return (1);
}

int	dup_fd_in(t_cmd *cmd)
{
	if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
		return (0);
	close(cmd->fd_in);
	return (1);
}

int	dup_heredoc(t_pipe *pipe_fd)
{
	if (dup2(pipe_fd->heredoc[0], STDIN_FILENO) == -1)
		return (0);
	close_pipe_fd(pipe_fd->heredoc);
	return (1);
}
