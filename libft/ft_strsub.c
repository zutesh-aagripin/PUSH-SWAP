/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:19:57 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 17:46:29 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned long	i;

	i = 0;
	if (!s)
		return (NULL);
	string = (char*)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	while (i < len)
	{
		string[i] = s[(start + i)];
		i++;
	}
	string[i] = '\0';
	return (string);
}
