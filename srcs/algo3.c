/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:24:21 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 18:30:38 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

void		sort_case_3(t_stack **a, t_stack **b)
{
	t_unit top;
	t_unit low;

	top = find_top(a);
	low = find_low(a);
	if (top.position == 3 && low.position == 2)
		op(sa, a, b);
	else if (top.position == 2 && low.position == 3)
		op(rra, a, b);
	else if (top.position == 2 && low.position == 1)
	{
		op(rra, a, b);
		op(sa, a, b);
	}
	else if (top.position == 1 && low.position == 2)
		op(ra, a, b);
	else if (top.position == 1 && low.position == 3)
	{
		op(sa, a, b);
		op(rra, a, b);
	}
}

void		pushposition(t_stack **a, int pos, t_stack **b)
{
	t_stack *ptr;
	t_stack *hold;

	ptr = *a;
	if (ptr->position == pos)
	{
		hold = ptr->next;
		ptr->next = *b;
		*b = ptr;
		*a = hold;
		return ;
	}
	while (ptr->next)
	{
		if (ptr->next->position == pos)
			break ;
		ptr = ptr->next;
	}
	hold = ptr->next;
	ptr->next = hold->next;
	hold->next = *b;
	*b = hold;
}

t_stack		*merge(t_stack **a, t_stack **b)
{
	t_unit	topa;
	t_unit	topb;
	t_stack *merge;

	merge = NULL;
	while (*a || *b)
	{
		renew_position(a);
		renew_position(b);
		topa = find_top(a);
		topb = find_top(b);
		if (*a && *b)
		{
			if (topa.nbr > topb.nbr)
				pushposition(a, topa.position, &merge);
			else
				pushposition(b, topb.position, &merge);
		}
		else if (*a)
			pushposition(a, topa.position, &merge);
		else if (*b)
			pushposition(b, topb.position, &merge);
	}
	return (merge);
}

void		merge_sort(t_stack **a)
{
	t_stack *b;
	int		si;
	int		half;

	if (!*a)
		return ;
	b = NULL;
	si = get_size(*a);
	if (si > 1)
	{
		half = si / 2;
		while (si > half)
		{
			silent(pb, a, &b);
			si--;
		}
		if (si > 1)
		{
			merge_sort(&b);
			merge_sort(a);
		}
	}
	*a = merge(a, &b);
}

int			quater(t_stack **a)
{
	t_stack *copy;
	t_stack *ptr;
	int		si;

	copy = copy_stack(a);
	merge_sort(&copy);
	si = get_size(copy);
	ptr = copy;
	si = si / 2;
	while (si--)
		ptr = ptr->next;
	si = ptr->nbr;
	free_stack(&copy);
	return (si);
}
