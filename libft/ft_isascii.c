/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:18 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 12:24:16 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main()
{
	char null_char;

	null_char = 0;
	printf("TEST");

	printf("char tester : C\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isascii('c'));

	printf("char tester : 0\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isascii('0'));

	printf("char tester : #\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isascii('#'));

	printf("char tester : \n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isascii(null_char));

	printf("char tester : b\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isascii('b'));
}*/
