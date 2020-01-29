/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:32:06 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 13:41:14 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	ptr = *alst;
	while (ptr != NULL)
	{
		del(ptr->content, ptr->content_size);
		*alst = ptr;
		ptr = ptr->next;
		free(*alst);
		*alst = NULL;
	}
}
