/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:23:33 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 16:09:12 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_atol(const char *str)
{
	int				start;
	long long int	nb;
	int				i;
	int				sign;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' ||
				str[start] == '\r' || str[start] == '\n' || str[start] ==
				'\v' || str[start] == '\f'))
		start++;
	nb = 0;
	i = start;
	sign = 1;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') ||
				(i == start && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
