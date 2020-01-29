/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:30:42 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/22 17:28:32 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = NULL;
	if (*s == c)
		ptr = (char*)s;
	while (*s++)
	{
		if (*s == c)
			ptr = (char*)s;
	}
	return (ptr);
}
