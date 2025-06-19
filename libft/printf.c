/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:14:21 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/05/06 20:24:06 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

int	ft_type(char c, va_list argptr)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar(va_arg(argptr, int));
	else if (c == 's')
		size = ft_putstr(va_arg(argptr, char *));
	else if (c == 'p')
		size = ft_putpointeur(va_arg(argptr, void *));
	else if (c == 'i' || c == 'd')
		size = ft_putnb(va_arg(argptr, int), 0);
	else if (c == 'u')
		size = ft_putunsigned_nb(va_arg(argptr, int), 0);
	else if (c == 'x')
		size = ft_puthexa_low(va_arg(argptr, int), 0);
	else if (c == 'X')
		size = ft_puthexa_upp(va_arg(argptr, int), 0);
	else if (c == '%')
		size = ft_putchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		size;

	va_start(argptr, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = size + ft_type(str[i + 1], argptr);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			if (str[i] != 0)
				i++;
			size++;
		}
	}
	va_end(argptr);
	return (size);
}
/*
int main()
{
	char  *str;
	
	str = "c5dwdasd";
	printf(" %d ", ft_printf("%p", 0));
	printf("\n");
	printf(" %d ", printf("%p", (void *)0));
}*/
