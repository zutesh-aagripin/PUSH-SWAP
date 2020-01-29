/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:28:00 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/22 14:28:21 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char*)s;
	if (*ptr == c)
		return (ptr);
	while (*ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}
	return (NULL);
}
