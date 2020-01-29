/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:31:14 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/22 15:49:09 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	lettercount(int *words, char const *s, char c, int wordcount)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < wordcount)
	{
		words[i] = 0;
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			words[j] = words[j] + 1;
		if (s[i] != c && s[i + 1] == c)
			j++;
		i++;
	}
}

static void	writeletters(char const *s, char **split, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			split[j][k] = s[i];
			k++;
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				j++;
			i++;
		}
		k = 0;
		if (s[i] != '\0')
			i++;
	}
}

static char	**ft_splitfree(char **split, int *words, int i, int wordcount)
{
	free(words);
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split[wordcount]);
	free(split);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char**split;
	int	*words;
	int i;
	int wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_words(s, c);
	i = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (wordcount + 1))))
		return (NULL);
	split[wordcount] = NULL;
	if (!(words = (int*)malloc(sizeof(int) * wordcount)))
		return (NULL);
	lettercount(words, s, c, wordcount);
	while (i < wordcount)
	{
		if (!(split[i] = (char*)malloc(sizeof(char) * (words[i] + 1))))
			return (ft_splitfree(split, words, (i - 1), wordcount));
		split[i][(words[i])] = '\0';
		i++;
	}
	writeletters(s, split, c);
	free(words);
	return (split);
}
