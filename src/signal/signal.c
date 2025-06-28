/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:58:40 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/28 11:31:08 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	ctrl_c(int sig)
{
	(void)sig;
	if (type_process(0, 0) != 2)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
	rl_on_new_line();
	rl_replace_line("", 0);
	g_state_signal = 130;
}

void	ctrl_c_bis(int sig)
{
	(void)sig;
	g_state_signal = 130;
}

void	ctrl_back(int sig)
{
	(void)sig;
	write(2, "Quit (core dumped)\n", 19);
	rl_replace_line("", 0);
	rl_on_new_line();
	g_state_signal = 131;
}

void	handle_signal_bis(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_bis);
}

void	handle_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
