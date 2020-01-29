/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:54:15 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 17:43:47 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int i;
	char*string;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	string = (char*)malloc(sizeof(char) * (i + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		string[i] = f(s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
