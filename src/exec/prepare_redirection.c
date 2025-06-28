/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:56:45 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/28 05:58:24 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static void	process_single_cmd_redirs(t_info *info, t_cmd *cmd)
{
	int	i;

	if (!cmd->name)
		return ;
	i = 0;
	while (cmd->name[i])
	{
		if (open_all(info, cmd, i) != 0)
		{
			if (info->return_value != 130)
				info->return_value = 1;
			cmd->redir_error = 1;
			break ;
		}
		i++;
	}
}

int	prepare_redirections(t_info *info)
{
	t_cmd	*current_cmd;

	current_cmd = info->cmd;
	while (current_cmd)
	{
		current_cmd->redir_error = 0;
		current_cmd->fd_in = STDIN_FILENO;
		current_cmd->fd_out = STDOUT_FILENO;
		process_single_cmd_redirs(info, current_cmd);
		current_cmd = current_cmd->next;
	}
	return (0);
}
