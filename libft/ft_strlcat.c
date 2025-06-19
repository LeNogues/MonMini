/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:23:48 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/15 15:40:53 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	uint_min(unsigned int x, unsigned int y)
{
	if (x > y)
		return (y);
	return (x);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = dst_len;
	while (src[dst_len - i] && dst_len + 1 < size)
	{
		dst[dst_len] = src[dst_len - i];
		dst_len++;
	}
	if (i < size)
		dst[dst_len] = 0;
	return (ft_strlen(src) + uint_min(size, i));
}
/*
int main()
{
    // Test 1: Test normal avec une taille suffisante
    char dst1[20] = "Hello";
    char src1[] = " World!";
    size_t size1 = 20;

    size_t result1 = ft_strlcat(dst1, src1, size1);
    printf("Result: %zu, dst1: %s\n", result1, dst1);  // "Hello World!"

    // Test 2: Test avec une taille insuffisante
    char dst2[10] = "Hi";
    char src2[] = " there!";
    size_t size2 = 8;

    size_t result2 = ft_strlcat(dst2, src2, size2);
    printf("Result: %zu, dst2: %s\n", result2, dst2);  // "Hi ther"

    // Test 3: Test avec une chaîne source vide
    char dst3[20] = "Hello";
    char src3[] = "";
    size_t size3 = 20;

    size_t result3 = ft_strlcat(dst3, src3, size3);
    printf("Result: %zu, dst3: %s\n", result3, dst3);  // "Hello"

    return 0;
}*/
