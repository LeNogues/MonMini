/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:00:59 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/15 15:38:20 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*zone;

	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (0);
	zone = (void *) malloc(nmemb * size);
	if (!zone)
		return (0);
	ft_bzero(zone, size * nmemb);
	return (zone);
}
