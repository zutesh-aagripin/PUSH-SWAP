/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:52:06 by aagripin          #+#    #+#             */
/*   Updated: 2019/11/11 21:52:08 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*str;

	if (!(str = ft_strnew(n)))
		return (NULL);
	str = ft_strncpy(str, (char *)s, n);
	str[n] = '\0';
	return (str);
}
