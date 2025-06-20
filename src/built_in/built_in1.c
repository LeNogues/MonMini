/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:12:07 by seb               #+#    #+#             */
/*   Updated: 2025/06/20 16:05:18 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static int	execute_built_in_bis(int type, t_info *info,
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

int	execute_built_in(int type, t_info *info, t_env *env, t_pipe *pipe_fd)
{
	int	result;


	if (info->cmd->nb_cmd == 1)
	{
		dup2(STDOUT_FILENO, info->cmd->fd_out);
		dup2(STDIN_FILENO, info->cmd->fd_in);
		if (!verif_file_builtin(info, pipe_fd))
			return (1);
	}
	result = execute_built_in_bis(type, info, env, pipe_fd);
	if (info->cmd->nb_cmd == 1)
	{
		if (info->cmd->fd_out)
		{
			close(info->cmd->fd_out);
			dup2(info->cmd->fd_out, STDOUT_FILENO);
		}
		if (info->cmd->fd_in)
			dup2(info->cmd->fd_in, STDIN_FILENO);
	}
	return (result);
}

static int	get_type(t_info *info)
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

int	choice_of_builtin(t_info *info, t_env *env, t_pipe *pipe_fd)
{
	int	result;
	int	type;

	result = -1;
	type = 0;
	info->cmd->fd_stdout = 0;
	info->cmd->fd_stdin = 0;
	if (!info->cmd->cmd)
		return (-1);
	type = get_type(info);
	if (type != 0)
		result = execute_built_in(type, info, env, pipe_fd);
	return (result);
}

void	hub(t_info *info)
{
	char	*line;

	info->return_value = 0;
	while (1)
	{
		g_state_signal = 1;
		signal(SIGQUIT, SIG_IGN);
		line = readline("\001\e[32m\002Minishell : \001\e[0m\002");
		if (!line)
			return ;
		if (line[0] != 0)
			add_histo_and_exec(info, line);
		if (g_state_signal == 130 || g_state_signal == 131)
			info->return_value = g_state_signal;
		free(line);
		signal(SIGINT, ctrl_c);
	}
}
