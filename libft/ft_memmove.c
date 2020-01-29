/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:27:02 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 19:46:32 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	char			*s;
	unsigned long	i;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			d[i] = s[i];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
