/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_histo_and_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:13:31 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 23:13:52 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	add_histo_and_exec(t_info *info, char *line)
{
	add_history(line);
	info->cmd = merge(info, line);
	if (info->cmd)
	{
		info->cmd_origin = info->cmd;
		exec(info);
		free_all_cmd(info->cmd_origin);
	}
}
