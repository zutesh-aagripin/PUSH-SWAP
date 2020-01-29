/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:24 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/06 20:46:55 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

void		push_lows(t_stack **a, t_stack **b)
{
	t_unit	low;
	int		si;

	while (*a && !check_stack(*a))
	{
		low = find_low(a);
		si = get_size(*a);
		if (si == 3)
		{
			sort_case_3(a, b);
			break ;
		}
		else if (low.position == 1)
			op(pb, a, b);
		else if (low.position == 2)
			op(sa, a, b);
		else
			op(get_nextontop(a, low), a, b);
	}
}

void		find_solution(t_stack **a, t_stack **b)
{
	int		si;
	t_unit	low;

	if (check_stack(*a))
		return ;
	si = get_size(*a);
	if (si <= 7)
		push_lows(a, b);
	else
		push_halves(a, b);
	while (*b)
		push_rrr(a, b);
	low = find_low(a);
	while (!check_stack(*a))
	{
		if (low.position - 1 < (si / 2))
			op(ra, a, b);
		else
			op(rra, a, b);
	}
}

int			main(int argc, char *argv[])
{
	t_stack *stack_1;
	t_stack *stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (!(parse_input(argc, argv, &stack_1)))
		return (ft_error("Error"));
	find_solution(&stack_1, &stack_2);
	free_stack(&stack_1);
	return (0);
}
