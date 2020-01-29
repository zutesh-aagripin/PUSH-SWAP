/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:24:42 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/16 12:24:27 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWS_H
# define PWS_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define MAXINT 2147483647
# define MININT	-2147483648
# define MAXINTLEN 11

typedef enum
{
	no,
	sa,
	ra,
	rra,
	pb,
	sb,
	rb,
	rrb,
	pa,
	rr,
	rrr,
	ss
}	t_operation;

typedef	struct			s_stack
{
	int					nbr;
	int					position;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_solution
{
	t_operation			op;
	struct s_solution	*next;
}						t_solution;

typedef struct			s_unit
{
	int					position;
	int					nbr;
}						t_unit;

void					free_stack(t_stack **stack);
t_unit					find_top(t_stack **stack);
t_unit					find_low(t_stack **stack);
t_unit					find_last(t_stack **stack, int pivot);
t_unit					find_next(t_stack **stack, int pivot);
int						check_stack(t_stack *stack);
void					st_revrot(t_stack **stack);
void					st_rotate(t_stack **stack);
void					st_push(t_stack **a, t_stack **b);
void					st_swap(t_stack **stack);
void					renew_position(t_stack **stack);
void					print_solution(t_operation this);
void					op(t_operation this, t_stack **a, t_stack **b);
void					silent(t_operation this, t_stack **a, t_stack **b);
t_stack					*create_stack(int *numbers, int size, int i);
t_stack					*copy_stack(t_stack **a);
int						get_size(t_stack *a);
void					sort_case_3(t_stack **a, t_stack **b);
void					pushposition(t_stack **a, int pos, t_stack **b);
t_stack					*merge(t_stack **a, t_stack **b);
void					merge_sort(t_stack **a);
int						quater(t_stack **a);
t_operation				get_nextontop(t_stack **a, t_unit next);
t_operation				get_nextontop_b(t_stack **b, t_unit next);
int						best_position(t_stack **b, int target,
		t_unit max, t_unit low);
t_operation				get_best(t_stack **b, int target, int si);
int						get_best_next(t_stack **b, int target, int si);
void					push_lows(t_stack **a, t_stack **b);
int						calculate_tmp(int tmp, int pos);
t_unit					determine_next(t_stack **a, t_stack **b);
t_unit					define_next(t_stack **a, int pivot);
void					push_rrr(t_stack **a, t_stack **b);
void					push_halves(t_stack **a, t_stack **b);
void					find_solution(t_stack **a, t_stack **b);
int						check_numbers(int *numbers, int argc);
int						incoming(int argc, char *argv[], int *numbers);
int						count(char **arg);
void					free_arg(char **arg);
int						parse_input(int argc, char **argv, t_stack **a);

#endif
