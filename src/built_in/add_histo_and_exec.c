/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_histo_and_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:13:31 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/28 03:51:40 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static int	is_empty(t_info *info)
{
	int	result;

	result = 1;
	if (!info->cmd)
		return (result);
	if (info->cmd->cmd)
		return (0);
	if (info->cmd->name)
		return (0);
	free_all_cmd(info->cmd);
	return (result);
}

void	add_histo_and_exec(t_info *info, char *line)
{
	int	result;

	add_history(line);
	info->cmd = merge(info, line);
	result = is_empty(info);
	if (!result)
	{
		info->cmd_origin = info->cmd;
		if (info->cmd->nb_cmd < 50)
			exec(info);
		else
		{
			printf("too many pipes\n");
			info->return_value = 1;
		}
		free_all_cmd(info->cmd_origin);
	}
}
