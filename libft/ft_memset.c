/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:18:46 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/19 17:34:21 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long i;
	unsigned char *fill;

	fill = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		fill[i] = c;
		i++;
	}
	return (b);
}
