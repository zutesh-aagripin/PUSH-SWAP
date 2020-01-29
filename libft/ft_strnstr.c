/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:34:13 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/19 20:21:27 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mytest(const char *str, const char *to_find, size_t len)
{
	while (*str && *to_find && len > 0)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
		len--;
	}
	if (*to_find == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char *ptr;

	ptr = (char*)haystack;
	if (*needle == '\0')
		return (ptr);
	while (*ptr != '\0' && len > 0)
	{
		if ((*ptr == *needle) && ft_mytest(ptr, needle, len))
			return (ptr);
		ptr++;
		len--;
	}
	return (0);
}
