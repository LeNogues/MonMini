/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:01:17 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 18:44:00 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
int main() {
    const char *str = "Hello, world!";
    
    // Test de ft_strchr
    char *result = ft_strchr(str, 'o');
    if (result) {
        printf("Found 'o' at position: %ld\n", result - str);
    } else {
        printf("'o' not found.\n");
    }

    // Recherche du caractère nul '\0'
    result = ft_strchr(str, '\0');
    if (result) {
        printf("Found '\\0' at position: %ld\n", result - str);
    }

    return 0;
}*/
