/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:53:42 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/26 14:45:21 by sle-nogu         ###   ########.fr       */
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
	int		status_fils;

	g_state_signal = 1;
	info->return_built = -1;
	info->pipe = malloc(sizeof(t_pipe) * 1);
	if (!info->pipe)
		exit_clean(1, info, info->env, info->pipe);
	if (pipe(info->pipe->old) == -1)
		exit_clean(1, info, info->env, info->pipe);
	if (!do_cmd(info, info->pipe))
		exit_clean(1, info, info->env, info->pipe);
	waitpid(info->last_pid, &status_fils, 0);
	if (info->last_pid != 0)
		info->return_value = WEXITSTATUS(status_fils);
	if (info->return_built != -1)
		info->return_value = info->return_built;
	info->last_pid = 0;
	if (g_state_signal == 130 || g_state_signal == 131)
		info->return_value = g_state_signal;
	while (waitpid(0, NULL, 0) != -1)
		;
	return ;
}
