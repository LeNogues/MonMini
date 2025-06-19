/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:22:42 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/04/01 12:23:59 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char delim)
{
	static char	*last;
	char		*token;

	if (!last)
		last = NULL;
	if (!str && !last)
		return (NULL);
	if (str)
		last = str;
	while (*last == delim && *last != 0)
		last++;
	if (*last == 0)
		return (0);
	token = last;
	while (*last != delim && *last != 0)
		last++;
	if (*last != 0)
		*last++ = 0;
	else
		last = NULL;
	return (token);
}
