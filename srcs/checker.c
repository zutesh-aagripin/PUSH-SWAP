/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:24 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/08 19:28:37 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

int		magic(char **line, t_stack **a, t_stack **b)
{
	if (ft_strequ(*line, "sa"))
		st_swap(a);
	else if (ft_strequ(*line, "sb"))
		st_swap(b);
	else if (ft_strequ(*line, "ss"))
		silent(ss, a, b);
	else if (ft_strequ(*line, "pa"))
		st_push(a, b);
	else if (ft_strequ(*line, "pb"))
		st_push(b, a);
	else if (ft_strequ(*line, "ra"))
		st_rotate(a);
	else if (ft_strequ(*line, "rb"))
		st_rotate(b);
	else if (ft_strequ(*line, "rr"))
		silent(rr, a, b);
	else if (ft_strequ(*line, "rra"))
		st_revrot(a);
	else if (ft_strequ(*line, "rrb"))
		st_revrot(b);
	else if (ft_strequ(*line, "rrr"))
		silent(rrr, a, b);
	else
		return (0);
	return (1);
}

int		get_instructions_and_act(t_stack **a, t_stack **b)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, "\0"))
		{
			ft_strdel(&line);
			return (1);
		}
		else if ((magic(&line, a, b)))
			ft_strdel(&line);
		else
		{
			ft_strdel(&line);
			return (ft_error("Error"));
		}
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack *stack_1;
	t_stack *stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (!(parse_input(argc, argv, &stack_1)))
		return (ft_error("Error"));
	if (get_instructions_and_act(&stack_1, &stack_2))
	{
		if (!check_stack(stack_1) || stack_2)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	free_stack(&stack_1);
	if (stack_2)
		free_stack(&stack_2);
	return (0);
}
