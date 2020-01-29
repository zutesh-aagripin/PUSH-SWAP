/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:24 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/08 19:19:19 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

int			check_stack(t_stack *stack)
{
	int		tmp;
	t_stack *ptr;

	if (!stack)
		return (0);
	ptr = stack;
	tmp = stack->nbr;
	while (ptr)
	{
		ptr = ptr->next;
		if (ptr)
		{
			if (tmp < ptr->nbr)
				tmp = ptr->nbr;
			else
				return (0);
		}
	}
	return (1);
}

void		st_revrot(t_stack **stack)
{
	t_stack *ptr;
	t_stack *ptr2;

	if (!*stack || !(*stack)->next)
		return ;
	ptr = *stack;
	ptr2 = *stack;
	while (ptr->next)
		ptr = ptr->next;
	while (ptr2->next != ptr)
		ptr2 = ptr2->next;
	ptr2->next = NULL;
	ptr->next = *stack;
	*stack = ptr;
}

void		st_rotate(t_stack **stack)
{
	t_stack *ptr;

	if (!*stack)
		return ;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *stack;
	ptr = ptr->next;
	*stack = (*stack)->next;
	ptr->next = NULL;
}

void		st_push(t_stack **a, t_stack **b)
{
	t_stack *ptr;

	if (!*b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = *a;
	*a = ptr;
}

void		st_swap(t_stack **stack)
{
	t_stack *ptr;

	if (!*stack || !(*stack)->next)
		return ;
	ptr = *stack;
	*stack = (*stack)->next;
	ptr->next = (*stack)->next;
	(*stack)->next = ptr;
}
