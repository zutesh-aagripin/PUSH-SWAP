/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:45:44 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/17 16:23:30 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long i;
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
