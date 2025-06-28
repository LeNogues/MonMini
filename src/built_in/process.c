/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:20:15 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/28 11:31:45 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	type_process(int action, int value)
{
	static int	type = 1;

	if (action == 0)
		return (type);
	else
		type = value;
	return (type);
}
