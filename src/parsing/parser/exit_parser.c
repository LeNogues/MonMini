/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:43:14 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/06/26 11:43:38 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	exit_and_free_clean_pars(t_token **head, t_cmd **final, t_info *info)
{
	free_tab(info->env->envp);
	free(info->env);
	free(info);
	free_token_list(head);
	free_all_cmd_bis(final);
	exit(1);
}
