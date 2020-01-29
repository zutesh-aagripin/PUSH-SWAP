/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:24 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 18:21:23 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

t_unit		find_next(t_stack **stack, int pivot)
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
			break ;
		}
		ptr = ptr->next;
	}
	return (tmp);
}

void		renew_position(t_stack **stack)
{
	int		pos;
	t_stack *ptr;

	if (!*stack)
		return ;
	pos = 1;
	ptr = *stack;
	while (ptr)
	{
		ptr->position = pos;
		pos++;
		ptr = ptr->next;
	}
}

t_stack		*create_stack(int *numbers, int size, int i)
{
	t_stack *stack;

	if (size > 0)
	{
		if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
			return (NULL);
		stack->nbr = numbers[i];
		stack->next = create_stack(numbers, size - 1, i + 1);
		stack->position = i + 1;
	}
	else
		stack = NULL;
	return (stack);
}

t_stack		*copy_stack(t_stack **a)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->nbr = (*a)->nbr;
	if ((*a)->next)
		stack->next = copy_stack(&(*a)->next);
	else
		stack->next = NULL;
	stack->position = (*a)->position;
	return (stack);
}

int			get_size(t_stack *a)
{
	int		size;
	t_stack	*ptr;

	size = 0;
	ptr = a;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
