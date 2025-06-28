/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:50:51 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/28 04:37:13 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	first_cmd(t_cmd **cmd_address, t_info *info, t_pipe *pipe_fd)
{
	t_cmd	*current_cmd;

	current_cmd = *cmd_address;
	handle_cmd(info, pipe_fd);
	if (current_cmd->next)
		*cmd_address = current_cmd->next;
	return (1);
}
