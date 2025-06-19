/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:07:05 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 12:44:31 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/*
int main() {
    // Test 1: Test normal avec une chaîne de caractères
    char str1[10] = "abcdefghi";
    printf("Avant ft_memset (str1): %s\n", str1);
    ft_memset(str1, 'X', 5);
    printf("Après ft_memset (str1): %s\n", str1);

    // Test 2: Test avec n = 0 (aucune modification)
    char str2[10] = "abcdefghi";
    printf("Avant ft_memset (str2): %s\n", str2);
    ft_memset(str2, 'X', 0);
    printf("Après ft_memset (str2): %s\n", str2);

    // Test 3: Test avec valeur maximale (255)
    char str3[10] = "abcdefghi";
    printf("Avant ft_memset (str3): %s\n", str3);
    ft_memset(str3, 255, 5);  // Remplir avec 0xFF
    printf("Après ft_memset (str3): ");
    for (int i = 0; i < 10; i++) {
        printf("%02x ", (unsigned char)str3[i]);
    }
    printf("\n");

    // Test 4: Test avec une chaîne vide
    char str4[1] = "";
    printf("Avant ft_memset (str4): %s\n", str4); // Affichera une chaîne vide
    ft_memset(str4, 'X', 1);
    printf("Après ft_memset (str4): %s\n", str4);

    // Test 5: Test avec n égal à la taille du tableau
    char str5[10] = "abcdefghi";
    printf("Avant ft_memset (str5): %s\n", str5);
    ft_memset(str5, 'X', 10);
    printf("Après ft_memset (str5): %s\n", str5);

    return 0;
}*/
