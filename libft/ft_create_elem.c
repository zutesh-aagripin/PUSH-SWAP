/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:57:03 by aagripin          #+#    #+#             */
/*   Updated: 2019/11/18 17:03:37 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list_c	*ft_create_elem(char *data)
{
	t_list_c*element;
	int		datasize;

	datasize = ft_strlen(data);
	if (!(element = (t_list_c*)malloc(sizeof(t_list_c))))
		return (NULL);
	if (!(element->data = (char*)malloc(sizeof(char) * (datasize + 1))))
		return (NULL);
	element->data = ft_strcpy(element->data, data);
	element->next = NULL;
	return (element);
}
