/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scanner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:56:22 by oettaqi           #+#    #+#             */
/*   Updated: 2025/05/06 20:26:19 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

t_scanner	*scanner(void)
{
	static t_scanner	scnr = {0};
	static int			init = 0;

	if (!init)
		init = 1;
	return (&scnr);
}

void	init_scanner(char *source)
{
	scanner()->start = source;
	scanner()->current = source;
}
