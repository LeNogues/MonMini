/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:07:00 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 12:25:00 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
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
	printf("valeur retourne : %d\n\n", ft_isalnum('c'));

	printf("char tester : 0\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isalnum('0'));

	printf("char tester : #\n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isalnum('#'));

	printf("char tester : \n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isalnum(null_char));

	printf("char tester : b\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isalnum('b'));
}*/
