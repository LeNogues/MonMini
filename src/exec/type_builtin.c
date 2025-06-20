/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:36:27 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/20 20:40:59 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	is_parent_builtin(int type)
{
	if (type != 0)
		return (1);
	return (0);
}

int	execute_built_in_bis(int type, t_info *info,
	t_env *env, t_pipe *pipe_fd)
{	
	if (type == 1)
		return (ft_cd(info->cmd->cmd, env));
	else if (type == 2)
		return (ft_pwd(env));
	else if (type == 3)
		return (ft_echo(info->cmd));
	else if (type == 4)
		return (ft_env(env));
	else if (type == 5)
		return (ft_unset(info->cmd->cmd, env));
	else if (type == 6)
		return (ft_export(info->cmd->cmd, env));
	if (type == 7)
		return (ft_exit(info, env, pipe_fd));
	return (0);
}

int	get_type(t_info *info)
{
	int	type;

	type = 0;
	if (ft_strncmp(info->cmd->cmd[0], "cd", 3) == 0)
		type = 1;
	else if (ft_strncmp(info->cmd->cmd[0], "pwd", 4) == 0)
		type = 2;
	else if (ft_strncmp(info->cmd->cmd[0], "echo", 5) == 0)
		type = 3;
	else if (ft_strncmp(info->cmd->cmd[0], "env", 4) == 0)
		type = 4;
	else if (ft_strncmp(info->cmd->cmd[0], "unset", 6) == 0)
		type = 5;
	else if (ft_strncmp(info->cmd->cmd[0], "export", 7) == 0)
		type = 6;
	else if (ft_strncmp(info->cmd->cmd[0], "exit", 5) == 0)
		type = 7;
	return (type);
}
