/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:14:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/08 15:07:04 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		transform(int len, char *str, long long int nbr, int base)
{
	char c;

	if (nbr / base)
		transform(len - 1, str, nbr / base, base);
	c = nbr % base + 48;
	if (c > '9')
		c = c + 39;
	str[len] = c;
}

char			*ft_itoa_base(long long int nbr, int base)
{
	char			*str;
	int				len;
	long long int	i;

	i = nbr;
	len = 1;
	if (i < 0 && base == 10)
		len++;
	while (i / base)
	{
		i = i / base;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		if (base == 10)
			str[0] = '-';
		nbr = -nbr;
	}
	transform(len - 1, str, nbr, base);
	return (str);
}
