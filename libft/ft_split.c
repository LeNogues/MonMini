/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:03:16 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/06/18 22:06:07 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	detect;

	i = 0;
	detect = 0;
	while (*str)
	{
		if (*str != c && detect == 0)
		{
			detect = 1;
			i++;
		}
		else if (*str == c)
			detect = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**tab;

	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (free_tab(tab), NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j++] = word_dup(s, start, i);
			start = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
/*
int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("%s\n", ft_split("chinimala", ' ')[0]);
}*/
