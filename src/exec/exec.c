/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:53:42 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 20:44:48 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	get_nb_heredoc(t_cmd *cmd)
{
	int	i;
	int	nb_heredoc;

	if (!cmd->in_or_out)
		return (0);
	i = 0;
	nb_heredoc = 0;
	while (cmd->in_or_out[i])
	{
		if (cmd->in_or_out[i] == HEREDOC)
			nb_heredoc++;
		i++;
	}
	return (nb_heredoc);
}

void	exec(t_info *info)
{
	t_pipe	*pipe_fd;
	int		status_fils;

	g_state_signal = 1;
	pipe_fd = malloc(sizeof(t_pipe) * 1);
	if (!pipe_fd)
		return ;
	if (pipe(pipe_fd->old) == -1)
		return (free(pipe_fd));
	if (!do_cmd(info, pipe_fd))
		return (close_pipe_fd(pipe_fd->old), free(pipe_fd));
	waitpid(info->last_pid, &status_fils, 0);
	info->return_value = WEXITSTATUS(status_fils);
	if (g_state_signal == 130 || g_state_signal == 131)
		info->return_value = g_state_signal;
	while (waitpid(0, NULL, 0) != -1)
		;
	return ;
}
