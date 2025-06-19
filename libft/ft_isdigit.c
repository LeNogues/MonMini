/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:04:57 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 12:21:03 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}
/*
int main()
{
	char null_char;

	null_char = 0;
	printf("TEST");

	printf("char tester : C\n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isdigit('C'));

	printf("char tester : 0\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isdigit('0'));

	printf("char tester : #\n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isdigit('#'));

	printf("char tester : \n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isdigit(null_char));

	printf("char tester : 9\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isdigit('9'));
}*/
