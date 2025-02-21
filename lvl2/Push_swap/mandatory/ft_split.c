/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:16:28 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/21 12:08:57 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cuenta cuántas palabras hay en la cadena
size_t count_words(const char *s, char c)
{
	size_t count;
	int in_word;

	count = 0;
	in_word = 0;

	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// Copia una palabra de la cadena original
static char *word_dup(const char *s, size_t start, size_t end)
{
	char *word;
	size_t i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);

	i = 0;
	while (start < end)
		word[i++] = s[start++];

	word[i] = '\0';
	return (word);
}

// Divide la cadena en palabras
char **ft_split(char const *s, char c)
{
	char **result;
	size_t words;
	size_t i = 0, j = 0, start = 0;

	if (!s)
		return NULL;

	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return NULL;

	while (s[i])
	{
		if (s[i] != c && j == 0)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && j > 0)
		{
			result[j - 1] = word_dup(s, start, i);
			if (!result[j - 1])
			{
				while (j--)
					free(result[j]);
				free(result);
				return NULL;
			}
		}
		i++;
	}
	result[words] = NULL;
	return result;
}
