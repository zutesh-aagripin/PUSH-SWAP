/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:24:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 21:12:49 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_findstart(char const *s)
{
	unsigned long i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static size_t	ft_findend(char const *s)
{
	int				empty;
	unsigned long	i;
	unsigned long	end;

	i = 0;
	empty = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') &&
				(s[i + 1] == ' ' || s[i + 1] == '\n' || s[i + 1] == '\t'
					|| s[i + 1] == '\0'))
		{
			end = i + 1;
			empty = 1;
		}
		i++;
	}
	if (empty == 1)
		return (end);
	else
		return (ft_strlen(s));
}

static void		ft_rewri(char const *s, char *string, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		string[i] = s[start];
		start++;
		i++;
	}
	string[i] = '\0';
}

char			*ft_strtrim(char const *s)
{
	char			*string;
	unsigned long	start;
	unsigned long	end;
	size_t			len;

	if (!s)
		return (NULL);
	start = ft_findstart(s);
	end = ft_findend(s);
	if (start == 0 && end == (ft_strlen(s)))
		len = ft_strlen(s);
	else
		len = end - start;
	if (!(string = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start == 0 && end == (len - 1))
		return (ft_strcpy(string, s));
	ft_rewri(s, string, start, end);
	return (string);
}
