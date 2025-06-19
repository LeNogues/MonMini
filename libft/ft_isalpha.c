/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:50 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 12:20:53 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 65 || c > 90) && (c < 97 || c > 122))
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
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isalpha('c'));

	printf("char tester : 0\n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isalpha('0'));

	printf("char tester : #\n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isalpha('#'));

	printf("char tester : \n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isalpha(null_char));

	printf("char tester : b\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isalpha('b'));
}*/
