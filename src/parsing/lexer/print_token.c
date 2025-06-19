/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:56:22 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/05/06 20:35:32 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	print_list(t_token **head)
{
	t_token	*parcours;
	int		j;

	parcours = *head;
	while (parcours != NULL)
	{
		j = 0;
		while (parcours->start[j] && j < parcours->length)
		{
			printf("%c", parcours->start[j]);
			j++;
		}
		printf(" %s \n", type_to_str(parcours->type));
		parcours = parcours->next;
	}
}

void	print_one_token(t_token *node)
{
	int	i;

	i = 0;
	while (i < node->length)
	{
		printf("%c", node->start[i]);
		i++;
	}
	printf("\n");
}
