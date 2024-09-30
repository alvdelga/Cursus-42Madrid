/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:01:38 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 18:01:49 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **split, int num_words)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = 0;
	len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		split[word] = (char *)malloc(sizeof(char) * (len + 1));
		if (split[word] == NULL)
			return (free_array(split, word));
		ft_strlcpy(split[word], &s[i - len], len + 1);
		len = 0;
		word++;
	}
	split[word] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!split)
		return (0);
	split = ft_split_words(s, c, split, num_words);
	return (split);
}
