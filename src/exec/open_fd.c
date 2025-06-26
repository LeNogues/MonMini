/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:27:23 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/26 14:59:52 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	open_out(t_cmd *cmd, const char *filename, int type)
{
	int	fd;
	int	flags;

	if (cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
	if (type == OUTPUT_APPEND)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(filename, flags, 0644);
	if (fd == -1)
	{
		perror(filename);
		cmd->fd_out = -1;
		return (1);
	}
	cmd->fd_out = fd;
	return (0);
}

int	open_in(t_cmd *cmd, const char *filename)
{
	int	fd;

	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		cmd->fd_in = -1;
		return (1);
	}
	cmd->fd_in = fd;
	return (0);
}
