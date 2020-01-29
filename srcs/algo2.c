/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:24:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 20:39:28 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

t_operation	get_nextontop(t_stack **a, t_unit next)
{
	int si;

	si = get_size(*a);
	if (next.position - 1 <= si / 2)
		return (ra);
	else
		return (rra);
}

t_operation	get_nextontop_b(t_stack **b, t_unit next)
{
	int si;

	si = get_size(*b);
	if (next.position - 1 <= si / 2)
		return (rb);
	else
		return (rrb);
}

int			best_position(t_stack **b, int target, t_unit max, t_unit low)
{
	t_stack *ptr;

	ptr = *b;
	while (ptr)
	{
		if (ptr->nbr > target && ptr->nbr <= max.nbr)
		{
			max.nbr = ptr->nbr;
			max.position = ptr->position;
		}
		else if (ptr->nbr < target && ptr->nbr >= low.nbr)
		{
			low.nbr = ptr->nbr;
			low.position = ptr->position;
		}
		ptr = ptr->next;
	}
	if (max.position == 1)
		return (0);
	return (low.position + 1);
}

t_operation	get_best(t_stack **b, int target, int si)
{
	t_unit	low;
	t_unit	max;
	int		pos;

	if (!*b)
		return (no);
	low = find_low(b);
	max = find_top(b);
	if (target > max.nbr)
	{
		pos = max.position + 1;
		if (pos > si)
			return (no);
	}
	else if (target < low.nbr)
		pos = low.position - 1;
	else
		pos = best_position(b, target, max, low);
	if (pos == 0)
		return (no);
	if (pos - 1 > si / 2)
		return (rra);
	else
		return (ra);
}

int			get_best_next(t_stack **b, int target, int si)
{
	t_unit	low;
	t_unit	max;
	int		pos;

	if (!*b)
		return (no);
	low = find_low(b);
	max = find_top(b);
	if (target > max.nbr)
	{
		pos = max.position + 1;
		if (pos > si)
			return (0);
	}
	else if (target < low.nbr)
		pos = low.position - 1;
	else
		pos = best_position(b, target, max, low);
	if (pos == 0)
		return (0);
	if (pos - 1 < si / 2)
		return (pos - 1);
	else
		return (-(si - pos + 1));
}
