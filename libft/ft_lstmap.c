/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:14:32 by aagripin          #+#    #+#             */
/*   Updated: 2019/09/20 16:15:26 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	ptr = f(lst);
	new = ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr->next = f(lst)))
		{
			while (ptr->next)
				free(ptr->next);
			return (NULL);
		}
		ptr = ptr->next;
	}
	return (new);
}
