/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:23:33 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 21:03:07 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

void		print_solution(t_operation this)
{
	if (this == sa)
		ft_putendl("sa");
	else if (this == ra)
		ft_putendl("ra");
	else if (this == rra)
		ft_putendl("rra");
	else if (this == pb)
		ft_putendl("pb");
	else if (this == sb)
		ft_putendl("sb");
	else if (this == rb)
		ft_putendl("rb");
	else if (this == rrb)
		ft_putendl("rrb");
	else if (this == pa)
		ft_putendl("pa");
	else if (this == ss)
		ft_putendl("ss");
	else if (this == rr)
		ft_putendl("rr");
	else if (this == rrr)
		ft_putendl("rrr");
}

void		op(t_operation this, t_stack **a, t_stack **b)
{
	if (this == no)
		return ;
	if (this == sa || this == ss)
		st_swap(a);
	if (this == ra || this == rr)
		st_rotate(a);
	if (this == rra || this == rrr)
		st_revrot(a);
	if (this == pb)
		st_push(b, a);
	if (this == rb || this == rr)
		st_rotate(b);
	if (this == rrb || this == rrr)
		st_revrot(b);
	if (this == pa)
		st_push(a, b);
	if (this == sb || this == ss)
		st_swap(b);
	print_solution(this);
	if (this == sa || this == ra || this == rra || this == pb || this == pa ||
			this == ss || this == rr || this == rrr)
		renew_position(a);
	if (this == sb || this == rb || this == rrb || this == pb || this == pa ||
			this == ss || this == rr || this == rrr)
		renew_position(b);
}

void		silent(t_operation this, t_stack **a, t_stack **b)
{
	if (this == no)
		return ;
	if (this == sa || this == ss)
		st_swap(a);
	if (this == ra || this == rr)
		st_rotate(a);
	if (this == rra || this == rrr)
		st_revrot(a);
	if (this == pb)
		st_push(b, a);
	if (this == rb || this == rr)
		st_rotate(b);
	if (this == rrb || this == rrr)
		st_revrot(b);
	if (this == pa)
		st_push(a, b);
	if (this == sb || this == ss)
		st_swap(b);
	if (this == sa || this == ra || this == rra || this == pb || this == pa ||
			this == ss || this == rr || this == rrr)
		renew_position(a);
	if (this == sb || this == rb || this == rrb || this == pb || this == pa ||
			this == ss || this == rr || this == rrr)
		renew_position(b);
}
