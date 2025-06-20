/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:37:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/20 15:29:42 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static void	handle_signal_bis(void)
{
	signal(SIGQUIT, ctrl_back);
	signal(SIGINT, ctrl_c_bis);
}

int	prepare_redirections(t_info *info)
{
	int	i;
	int	result;

	info->cmd->fd_in = STDIN_FILENO;
	info->cmd->fd_out = STDOUT_FILENO;
	if (!info->cmd->name)
		return (1);
	i = 0;
	while (info->cmd->name[i])
	{
		result = open_all(info, i);
		if (result <= 0)
		{
			if (info->cmd->fd_in > STDIN_FILENO)
				close(info->cmd->fd_in);
			if (info->cmd->fd_out > STDOUT_FILENO)
				close(info->cmd->fd_out);
			return (0);
		}
		i++;
	}
	return (1);
}

void	close_redirection_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
}

void	open_and_execute(t_info *info, t_pipe *pipe_fd)
{
	signal(SIGINT, ctrl_c);
	dup_no_fd(info->cmd, pipe_fd);
	close_redirection_fds(info->cmd);
	if (choice_of_builtin(info, info->env, pipe_fd) == -1)
		execute(info, info->env, pipe_fd);
	else
		free_cmd_env_pipe_bis(info, info->env, pipe_fd);
}

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

static int	is_parent_builtin(int type)
{
	if (type != 0)
		return (1);
	return (0);
}

int	execute_parent_builtin(int type, t_info *info, t_env *env)
{
	int	saved_stdout;
	int	saved_stdin;
	int	result;
	int id;

	id = 0;
	result = 0;
	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (info->cmd->fd_out != STDOUT_FILENO)
		dup2(info->cmd->fd_out, STDOUT_FILENO);
	if (info->cmd->fd_in != STDIN_FILENO)
		dup2(info->cmd->fd_in, STDIN_FILENO);
	if (type >=1 && type <= 6)
		result = execute_built_in_bis(type, info, env, NULL);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	if (type == 7)
		result = ft_exit(info, env, info->pipe);
	if (type >= 1 && type <= 7)
		id = fork();
	if (id == 0)
		exit_clean(result, info, env, info->pipe);
	return (result);
}

void	handle_cmd(t_info *info, t_pipe *pipe_fd)
{
	int	id;
	int	type;

	id = -1;
	if (!prepare_redirections(info))
	{
		if (info->return_value != 130)
			info->return_value = 1;
		return ;
	}
	if (info->cmd->cmd)
	{
		type = get_type(info);
		if (type != 0 && info->cmd->nb_cmd == 1 && is_parent_builtin(type))
			info->return_value = execute_parent_builtin(type, info, info->env);
		else
		{
			handle_signal_bis();
			id = fork();
			g_state_signal = 2;
			if (id == 0)
				open_and_execute(info, pipe_fd);
			info->last_pid = id;
		}
		if (g_state_signal == 130 || g_state_signal == 131)
			info->return_value = g_state_signal;
		if (info->cmd->nb_cmd == 1)
			close_pipe_fd(pipe_fd->old);
	}
		close_redirection_fds(info->cmd);
}
