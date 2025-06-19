/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:41:19 by seb               #+#    #+#             */
/*   Updated: 2025/05/06 20:29:03 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	ft_list_len(t_cmd *cmd)
{
	int		count;
	t_cmd	*counter_ptr;
	t_cmd	*current;

	count = 0;
	counter_ptr = cmd;
	while (counter_ptr != NULL)
	{
		count++;
		counter_ptr = counter_ptr->next;
	}
	current = cmd;
	while (current != NULL)
	{
		current->nb_cmd = count;
		current->pos = 2;
		if (current->next == NULL)
			current->pos = 3;
		if (current == cmd)
			current->pos = 1;
		current = current->next;
	}
}
