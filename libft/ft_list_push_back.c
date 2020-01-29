/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:32:14 by aagripin          #+#    #+#             */
/*   Updated: 2019/11/18 17:03:46 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list_c **begin_list, char *data)
{
	t_list_c	*element;

	element = *begin_list;
	if (*begin_list && begin_list)
	{
		element = *begin_list;
		while (element->next)
			element = element->next;
		element->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
