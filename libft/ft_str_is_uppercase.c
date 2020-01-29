/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 23:18:46 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 20:24:35 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if ('A' <= *str && *str <= 'Z')
			str++;
		else
			return (0);
	}
	return (1);
}
