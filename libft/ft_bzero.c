/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:00:44 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 14:32:30 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (s);
}
/*
int main() {
    // Test 1: Test normal avec une chaîne de caractères
    char str1[26] = "abcdefghijklmnopqrstuvwxyz";
    printf("Avant ft_bzero (str1): %s\n", str1);
    bzero(str1, 1);
    printf("Après ft_bzero (str1): %c\n\n", str1);

    // Test 2: Test avec n = 0 (aucune modification)
    char str2[10] = "abcdefghi";
    printf("Avant ft_bzero (str2): %s\n", str2);
    ft_bzero(str2, 0);
    printf("Après ft_bzero (str2): %s\n\n", str2);

    // Test 3: Test avec toute la chaîne remplie de zéros
    char str3[10] = "abcdefghi";
    printf("Avant ft_bzero (str3): %s\n", str3);
    ft_bzero(str3, 10);  // Remplir toute la chaîne avec des zéros
    printf("Après ft_bzero (str3): ");
    for (int i = 0; i < 10; i++) {
        printf("%02x ", (unsigned char)str3[i]);  // Affichage en hex
    }
    printf("\n\n");

    // Test 4: Test avec une chaîne vide
    char str4[1] = "";
    printf("Avant ft_bzero (str4): %s\n", str4); // Affichera une chaîne vide
    ft_bzero(str4, 1);
    printf("Après ft_bzero (str4): %s\n\n", str4);

    // Test 5: Test avec n égal à la taille du tableau
    char str5[10] = "abcdefghi";
    printf("Avant ft_bzero (str5): %s\n", str5);
    ft_bzero(str5, 10);
    printf("Après ft_bzero (str5): %s\n\n", str5);

    return 0;
}*/
