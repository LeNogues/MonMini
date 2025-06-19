/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:58:56 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 18:29:26 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c <= 31) || c >= 127)
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
	printf("valeur retourne : %d\n\n", ft_isprint('c'));

	printf("char tester : 0\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isprint('0'));

	printf("char tester : #\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isprint('#'));

	printf("char tester : \n");
	printf("valeur attendu : 0\n");
	printf("valeur retourne : %d\n\n", ft_isprint(null_char));

	printf("char tester : b\n");
	printf("valeur attendu : 1\n");
	printf("valeur retourne : %d\n\n", ft_isprint('b'));
}*/
