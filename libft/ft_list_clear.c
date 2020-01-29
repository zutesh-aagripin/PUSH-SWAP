/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 23:37:25 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/24 19:27:52 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_list_clear(t_list_c **begin_list)
{
	t_list_c	*holder;

	while (*begin_list)
	{
		holder = *begin_list;
		*begin_list = (*begin_list)->next;
		free(holder->data);
		holder->data = NULL;
		free(holder);
		holder = NULL;
	}
	*begin_list = NULL;
}
