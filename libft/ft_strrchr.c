/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:34:30 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 14:35:17 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (0);
}
/*
int main() {
    const char *str = "Hello, world!";

    // Test de ft_strrchr
    char *result = ft_strrchr(str, 'o');
    if (result) {
        printf("Found 'o' at position: %ld\n", result - str);
    } else {
        printf("'o' not found.\n");
    }

    // Recherche du caractère nul '\0'
    result = ft_strrchr(str, '\0');
    if (result) {
        printf("Found '\\0' at position: %ld\n", result - str);
    }

    return 0;
}*/
