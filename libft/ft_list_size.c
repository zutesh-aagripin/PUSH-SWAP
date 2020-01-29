/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:03:15 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/24 22:04:53 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list_c *begin_list)
{
	int			counter;
	t_list_c	*holder;

	counter = 0;
	if (!begin_list)
		return (counter);
	holder = begin_list;
	while (holder)
	{
		counter = ft_strlen(holder->data) + counter;
		holder = holder->next;
	}
	return (counter);
}
