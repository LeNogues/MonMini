/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:03:28 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 19:23:25 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	do_cmd(t_info *info, t_pipe *pipe_fd)
{
	first_cmd(&info->cmd, info, pipe_fd);
	if (!loop_on_middle(info, pipe_fd))
		return (0);
	while (info->cmd->next)
		info->cmd = info->cmd->next;
	if (info->cmd->nb_cmd >= 2)
		handle_cmd(info, pipe_fd);
	close_pipe_fd(pipe_fd->old);
	free(pipe_fd);
	return (1);
}
