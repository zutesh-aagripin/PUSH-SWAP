/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:24 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/16 12:19:49 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

void		free_stack(t_stack **stack)
{
	t_stack *ptr;

	if (!*stack)
		return ;
	while (*stack)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
		ptr = NULL;
	}
}

t_unit		find_top(t_stack **stack)
{
	t_unit	tmp;
	t_stack *ptr;

	tmp.nbr = 0;
	tmp.position = 0;
	if (!*stack)
		return (tmp);
	ptr = *stack;
	tmp.nbr = ptr->nbr;
	tmp.position = ptr->position;
	while (ptr)
	{
		ptr = ptr->next;
		if (ptr)
			if (tmp.nbr < ptr->nbr)
			{
				tmp.nbr = ptr->nbr;
				tmp.position = ptr->position;
			}
	}
	return (tmp);
}

t_unit		find_low(t_stack **stack)
{
	t_unit	tmp;
	t_stack *ptr;

	ptr = *stack;
	tmp.nbr = ptr->nbr;
	tmp.position = ptr->position;
	while (ptr)
	{
		ptr = ptr->next;
		if (ptr)
			if (tmp.nbr > ptr->nbr)
			{
				tmp.nbr = ptr->nbr;
				tmp.position = ptr->position;
			}
	}
	return (tmp);
}

t_unit		find_last(t_stack **stack, int pivot)
{
	t_stack *ptr;
	t_unit	tmp;

	ptr = *stack;
	tmp.nbr = 0;
	tmp.position = 0;
	while (ptr)
	{
		if (ptr->nbr <= pivot)
		{
			tmp.nbr = ptr->nbr;
			tmp.position = ptr->position;
		}
		ptr = ptr->next;
	}
	return (tmp);
}
