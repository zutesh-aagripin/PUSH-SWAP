/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:34:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/19 20:21:46 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mytest(char *str, const char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	if (*to_find == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char *ptr;

	ptr = (char*)haystack;
	if (*needle == '\0')
		return (ptr);
	while (*ptr != '\0')
	{
		if ((*ptr == *needle) && ft_mytest(ptr, needle))
			return (ptr);
		ptr++;
	}
	return (0);
}
