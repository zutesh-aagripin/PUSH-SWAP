/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:29:30 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 16:30:23 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_turn(int n, int decimal, char *result)
{
	if (n / 10)
		ft_turn((n / 10), (decimal - 1), result);
	result[decimal] = n % 10 + 48;
}

static char	*ft_minint(char *result)
{
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	int	decimal;
	int	nb;
	char*result;

	decimal = 1;
	nb = n;
	while (nb / 10)
	{
		decimal++;
		nb = nb / 10;
	}
	if (n < 0)
		decimal++;
	if (!(result = (char*)malloc(sizeof(char) * (decimal + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_minint(result));
	result[decimal] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	ft_turn(n, decimal - 1, result);
	return (result);
}
