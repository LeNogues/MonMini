/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sebastienlenogues@gmail.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:03:52 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/14 18:18:28 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	size_nb(long n)
{
	int	size;

	size = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	is_neg(int *n, int fd)
{
	if (*n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	write(fd, "-", 1);
	*n = -*n;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nb;
	int		size;
	int		single_number[10];
	int		i;

	i = 0;
	size = size_nb(n);
	if (n < 0)
		is_neg(&n, fd);
	if (n == -2147483648)
		return ;
	while (i < size)
	{
		single_number[i] = n % 10;
		n /= 10;
		i++;
	}
	while (i - 1 >= 0)
	{
		nb = single_number[i - 1] + '0';
		write(fd, &nb, 1);
		i--;
	}
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), 1);
}*/
