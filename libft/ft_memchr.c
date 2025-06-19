/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:27:21 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/15 15:39:23 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
/*
int main() {
    // Test 1: Recherche d'un caractère dans une chaîne de caractères
    char str1[] = "Hello, World!";
    char *result1 = ft_memchr(str1, 'W', 13);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'W'\n", str1);
    printf("Résultat attendu : 'World!' \n");
    if (result1) {
        printf("Résultat obtenu : \"%s\"\n\n", result1);  
    } else {
        printf("Résultat obtenu : NULL\n\n");
    }

    // Test 2: Recherche d'un caractère non présent
    char str2[] = "Hello, World!";
    char *result2 = ft_memchr(str2, 'z', 13);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'z'\n", str2);
    printf("Résultat attendu : NULL (caractère non trouvé)\n");
    if (!result2) {
        printf("Résultat obtenu : NULL\n\n");
    } else {
        printf("Résultat obtenu : \"%s\"\n\n", result2);
    }

    // Test 3: Recherche dans une chaîne vide
    char str3[] = "";
    char *result3 = ft_memchr(str3, 'H', 0);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'H'\n", str3);
    printf("Résultat attendu : NULL (chaîne vide)\n");
    if (!result3) {
        printf("Résultat obtenu : NULL\n\n");
    } else {
        printf("Résultat obtenu : \"%s\"\n\n", result3);
    }

    // Test 4: Recherche sur une seule position
    char str4[] = "A";
    char *result4 = ft_memchr(str4, 'A', 1);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'A'\n", str4);
    printf("Résultat attendu : 'A' \n");
    if (result4) {
        printf("Résultat obtenu : \"%s\"\n\n", result4);
    } else {
        printf("Résultat obtenu : NULL\n\n");
    }

    // Test 5: Recherche au début de la chaîne
    char str5[] = "ABCDEFG";
    char *result5 = ft_memchr(str5, 'A', 7);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'A'\n", str5);
    printf("Résultat attendu : 'ABCDEFG' \n");
    if (result5 && *result5 == 'A') {
        printf("Résultat obtenu : \"%s\"\n\n", result5);  
    } else {
        printf("Résultat obtenu : NULL\n\n");
    }

    // Test 6: Recherche au milieu de la chaîne
    char str6[] = "ABCDEFG";
    char *result6 = ft_memchr(str6, 'D', 7);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'D'\n", str6);
    printf("Résultat attendu : 'DEFG' \n");
    if (result6 && *result6 == 'D') {
        printf("Résultat obtenu : \"%s\"\n\n", result6);  
    } else {
        printf("Résultat obtenu : NULL\n\n");
    }

    // Test 7: Recherche à la fin de la chaîne
    char str7[] = "ABCDEFG";
    char *result7 = ft_memchr(str7, 'G', 7);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'G'\n", str7);
    printf("Résultat attendu : 'G' \n");
    if (result7 && *result7 == 'G') {
        printf("Résultat obtenu : \"%s\"\n\n", result7);  
    } else {
        printf("Résultat obtenu : NULL\n\n");
    }

    // Test 8: Recherche avec un `n` plus grand que la taille de la chaîne
    char str8[] = "Hello";
    char *result8 = ft_memchr(str8, 'o', 10);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'o'\n", str8);
    printf("Résultat attendu : 'o' \n");
    if (result8) {
        printf("Résultat obtenu : \"%s\"\n\n", result8);  
    } else {
        printf("Résultat obtenu : NULL\n\n");
    }

    // Test 9: Recherche du caractère au-delà de n
    char str9[] = "abcdef";
    char *result9 = ft_memchr(str9, 'f', 5);  
    printf("Etat avant: chaîne = \"%s\", recherche = 'f' avec n = 5\n", str9);
    printf("Résultat attendu : NULL (caractère 'f' au-delà de n)\n");
    if (!result9) {
        printf("Résultat obtenu : NULL\n\n");
    } else {
        printf("Résultat obtenu : \"%s\"\n\n", result9);
    }

    return 0;
}*/
