/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:23:26 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/05/06 20:23:48 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_nb(unsigned int nb, int size)
{
	if (nb < 10)
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
	else
	{
		size = ft_putunsigned_nb(nb / 10, size);
		nb = nb % 10 + 48;
		write(1, &nb, 1);
	}
	size += 1;
	return (size);
}

int	ft_putnb(int nb, int size)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		size++;
	}
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
	}
	else
	{
		size = ft_putnb(n / 10, size);
		n = n % 10 + 48;
		write(1, &n, 1);
	}
	size += 1;
	return (size);
}

int	ft_puthexa_low(unsigned int nb, int size)
{
	char	*set_low;

	set_low = "0123456789abcdef";
	if (nb <= 15)
	{
		write(1, &set_low[nb], 1);
	}
	else
	{
		size = ft_puthexa_low(nb / 16, size);
		write(1, &set_low[nb % 16], 1);
	}
	size += 1;
	return (size);
}

int	ft_puthexa_upp(unsigned int nb, int size)
{
	char	*set_upp;

	set_upp = "0123456789ABCDEF";
	if (nb <= 15)
		write(1, &set_upp[nb], 1);
	else
	{
		size = ft_puthexa_upp(nb / 16, size);
		write(1, &set_upp[nb % 16], 1);
	}
	size += 1;
	return (size);
}
