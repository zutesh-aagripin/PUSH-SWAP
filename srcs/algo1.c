/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:24:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 20:34:51 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

int			calculate_tmp(int tmp, int pos)
{
	if (tmp <= 0 && pos <= 0)
	{
		if (-tmp > -pos)
			tmp = -tmp;
		else if (-pos >= -tmp)
			tmp = -pos;
	}
	else if (tmp >= 0 && pos >= 0)
	{
		if (tmp > pos)
			tmp = tmp + 1 - 1;
		else if (pos >= tmp)
			tmp = pos;
	}
	else if (tmp >= 0 && pos <= 0)
		tmp = tmp - pos;
	else if (tmp <= 0 && pos >= 0)
		tmp = pos - tmp;
	return (tmp);
}

t_unit		determine_next(t_stack **a, t_stack **b)
{
	int		bestop;
	int		tmp;
	int		pos;
	t_stack *ptr;
	t_unit	next;

	bestop = 100000;
	ptr = *b;
	while (ptr)
	{
		tmp = get_best_next(a, ptr->nbr, get_size(*a));
		if (ptr->position > ((get_size(*b) / 2) + 1))
			pos = -(get_size(*b) - ptr->position + 1);
		else
			pos = (ptr->position - 1);
		if ((tmp = calculate_tmp(tmp, pos)) < bestop)
		{
			bestop = tmp;
			next.nbr = ptr->nbr;
			next.position = ptr->position;
		}
		ptr = ptr->next;
	}
	return (next);
}

t_unit		define_next(t_stack **a, int pivot)
{
	t_unit	next;
	t_unit	last;
	int		diffnext;
	int		difflast;
	int		si;

	next = find_next(a, pivot);
	last = find_last(a, pivot);
	si = get_size(*a);
	diffnext = (next.position - 1 <= si / 2) ? next.position - 1 :
		si - next.position + 1;
	difflast = (last.position - 1 <= si / 2) ? last.position - 1 :
		si - last.position + 1;
	if (diffnext <= difflast)
		return (next);
	else
		return (last);
}

void		push_rrr(t_stack **a, t_stack **b)
{
	t_unit		next;
	t_operation aop;
	t_operation bop;

	next = determine_next(a, b);
	if (next.position == 1)
	{
		while ((aop = get_best(a, next.nbr, get_size(*a))) != no)
			op(aop, a, b);
		op(pa, a, b);
	}
	else
	{
		aop = get_best(a, next.nbr, get_size(*a));
		bop = get_nextontop_b(b, next);
		if (bop == rb && aop == ra)
			op(rr, a, b);
		else if (bop == rrb && aop == rra)
			op(rrr, a, b);
		else
		{
			op(aop, a, b);
			op(bop, a, b);
		}
	}
}

void		push_halves(t_stack **a, t_stack **b)
{
	int			pivot;
	t_unit		next;

	next.position = 0;
	pivot = quater(a);
	while (*a)
	{
		if (get_size(*a) == 2)
			break ;
		next = define_next(a, pivot);
		if (next.position == 0)
			pivot = quater(a);
		else if (next.position == 1)
			op(pb, a, b);
		else
			op(get_nextontop(a, next), a, b);
	}
}
