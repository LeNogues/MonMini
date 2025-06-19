/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:45:28 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/19 16:19:37 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	ft_pwd(t_env *env)
{
	char	*current_path;

	if (!env)
		return (0);
	current_path = getcwd(NULL, 0);
	if (!current_path)
	{
		printf("Error retrieving current working directory\n");
		return (0);
	}
	printf("%s\n", current_path);
	free(current_path);
	return (1);
}
