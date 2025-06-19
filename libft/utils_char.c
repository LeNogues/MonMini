/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:19:23 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/12/12 11:36:37 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putpointeur(void *s)
{
	unsigned long	adresse;
	int				size;

	if (!s)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	adresse = (unsigned long)s;
	write(1, "0x", 2);
	size = ft_puthexa_addr(adresse, 0) + 2;
	return (size);
}

int	ft_puthexa_addr(unsigned long nb, int size)
{
	char	*set_low;

	set_low = "0123456789abcdef";
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb > 15)
	{
		size = ft_puthexa_addr(nb / 16, size);
	}
	write(1, &set_low[nb % 16], 1);
	size += 1;
	return (size);
}
