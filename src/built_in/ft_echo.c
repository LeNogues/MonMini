/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:44:45 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/19 16:19:50 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

static int	check_flags(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (!cmd->cmd[1])
		return (1);
	while (cmd->cmd[i] && cmd->cmd[i][0] == '-' && cmd->cmd[i][j] == 'n')
	{
		if (cmd->cmd[i][j] != 'n')
			break ;
		j++;
		if (!cmd->cmd[i][j])
		{
			i++;
			j = 1;
		}
	}
	return (i);
}

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	newline;
	int	size;

	newline = 1;
	i = check_flags(cmd);
	if (i != 1)
		newline = 0;
	if (cmd->cmd[i])
	{
		while (cmd->cmd[i])
		{
			size = ft_strlen(cmd->cmd[i]);
			write(1, cmd->cmd[i], size);
			if (cmd->cmd[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (newline)
		write(1, "\n", 1);
	return (0);
}
