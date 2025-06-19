/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:04:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 14:34:40 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			size_src;

	size_src = ft_strlen(src);
	i = 0;
	while (i + 1 < size && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = 0;
	return (size_src);
}
/*
int main() {
    // Test 1: Test normal avec une taille suffisante
    char str1[20] = "Hello, world!";
    char dst1[20] = "";
    printf("Avant ft_strlcpy (str1): %s\n", str1);
    ft_strlcpy(dst1, str1, 20);
    printf("Après ft_strlcpy (dst1): %s\n", dst1);
    printf("Longueur de la source : %zu\n\n", ft_strlen(str1));

    // Test 2: Test avec une taille insuffisante (la chaîne source est tronquée)
    char str2[20] = "Hello, world!";
    char dst2[10] = "";
    printf("Avant ft_strlcpy (str2): %s\n", str2);
    ft_strlcpy(dst2, str2, 6);  
    printf("Après ft_strlcpy (dst2): %s\n", dst2);
    printf("Longueur de la source : %zu\n\n", ft_strlen(str2));

    // Test 3: Test avec une taille de 0 (aucune donnée copiée)
    char str3[20] = "Hello, world!";
    char dst3[20] = "";
    printf("Avant ft_strlcpy (str3): %s\n", str3);
    ft_strlcpy(dst3, str3, 0);  // Ne rien copier, `dst3` doit rester vide
    printf("Après ft_strlcpy (dst3): '%s'\n", dst3); 
    printf("Longueur de la source : %zu\n\n", ft_strlen(str3));

    // Test 4: Test avec une chaîne vide (src vide)
    char str4[20] = "";
    char dst4[20] = "";
    printf("Avant ft_strlcpy (str4): '%s'\n", str4);
    ft_strlcpy(dst4, str4, 10);  // Ne rien copier, `dst4` doit rester vide
    printf("Après ft_strlcpy (dst4): '%s'\n", dst4); 
    printf("Longueur de la source : %zu\n\n", ft_strlen(str4));

    // Test 5: Test avec une chaîne source plus petite que la taille spécifiée
    char str5[20] = "Hi!";
    char dst5[20] = "";
    printf("Avant ft_strlcpy (str5): %s\n", str5);
    ft_strlcpy(dst5, str5, 20);  // Copier toute la chaîne source
    printf("Après ft_strlcpy (dst5): %s\n", dst5);
    printf("Longueur de la source : %zu\n\n", ft_strlen(str5));

    return 0;
}*/
