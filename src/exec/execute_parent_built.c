/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent_built.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:12:28 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/27 11:19:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static void	save_standard_fds(int *s_in, int *s_out, t_info *info, t_env *env)
{
	*s_in = dup(STDIN_FILENO);
	if (*s_in == -1)
		exit_clean(1, info, env, info->pipe);
	*s_out = dup(STDOUT_FILENO);
	if (*s_out == -1)
	{
		close(*s_in);
		exit_clean(1, info, env, info->pipe);
	}
}

static void	redirect_io_for_builtin(t_info *info, int s_in, int s_out)
{
	if (info->cmd->fd_out != STDOUT_FILENO)
	{
		if (dup2(info->cmd->fd_out, STDOUT_FILENO) == -1)
		{
			close(s_in);
			close(s_out);
			exit_clean(1, info, info->env, info->pipe);
		}
	}
	if (info->cmd->fd_in != STDIN_FILENO)
	{
		if (dup2(info->cmd->fd_in, STDIN_FILENO) == -1)
		{
			close(s_in);
			close(s_out);
			if (info->cmd->fd_out != STDOUT_FILENO)
				close(info->cmd->fd_out);
			exit_clean(1, info, info->env, info->pipe);
		}
	}
}

static void	restore_standard_fds(int s_in, int s_out, t_info *info)
{
	if (dup2(s_out, STDOUT_FILENO) == -1)
	{
		close(s_in);
		close(s_out);
		exit_clean(1, info, info->env, info->pipe);
	}
	close(s_out);
	if (dup2(s_in, STDIN_FILENO) == -1)
	{
		close(s_in);
		exit_clean(1, info, info->env, info->pipe);
	}
	close(s_in);
}

int	execute_parent_builtin(int type, t_info *info, t_env *env)
{
	int	saved_stdout;
	int	saved_stdin;
	int	result;

	result = 0;
	save_standard_fds(&saved_stdin, &saved_stdout, info, env);
	redirect_io_for_builtin(info, saved_stdin, saved_stdout);
	if (type >= 1 && type <= 6)
		result = execute_built_in_bis(type, info, env, NULL);
	restore_standard_fds(saved_stdin, saved_stdout, info);
	if (type == 7)
		result = ft_exit(info, env, info->pipe);
	return (result);
}
