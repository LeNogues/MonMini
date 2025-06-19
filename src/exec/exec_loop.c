/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:04:43 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 20:43:58 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	pipecpy(int new_fd[2], int old_fd[2])
{
	close(old_fd[0]);
	close(old_fd[1]);
	old_fd[0] = new_fd[0];
	old_fd[1] = new_fd[1];
}

int	loop_on_middle(t_info *info, t_pipe *pipe_fd)
{
	int	i;

	i = 0;
	while (i < info->cmd->nb_cmd - 2)
	{
		if (pipe(pipe_fd->new) == -1)
			return (0);
		handle_cmd(info, pipe_fd);
		pipecpy(pipe_fd->new, pipe_fd->old);
		info->cmd = info->cmd->next;
		i++;
	}
	return (1);
}
