/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_scanner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:59:36 by oettaqi           #+#    #+#             */
/*   Updated: 2025/06/20 13:03:37 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	peek_next(void)
{
	if (is_at_end())
		return (0);
	return (scanner()->current[1]);
}

char	peek(void)
{
	return (*scanner()->current);
}

int	is_at_end(void)
{
	if (peek() == 0)
		return (1);
	else
		return (0);
}

char	advance(void)
{
	scanner()->current++;
	return (scanner()->current[-1]);
}
