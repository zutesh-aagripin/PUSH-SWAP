/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:33:24 by aagripin          #+#    #+#             */
/*   Updated: 2019/12/08 19:25:11 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pws.h"

int			check_numbers(int *numbers, int argc)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			incoming(int argc, char *argv[], int *numbers)
{
	long int	test;
	int			i;
	int			j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				return (0);
			j++;
			if (j > MAXINTLEN)
				return (0);
		}
		test = (j > 0) ? ft_atol(argv[i]) : 111111111111;
		if (test > MAXINT || test < MININT)
			return (0);
		numbers[i] = (int)test;
		i++;
	}
	if (!argc || !check_numbers(numbers, argc))
		return (0);
	return (1);
}

int			count(char **arg)
{
	char	**ptr;
	int		count;

	count = 0;
	ptr = arg;
	while (*ptr)
	{
		ptr++;
		count++;
	}
	return (count);
}

int			free_all(char **arg, int **numbers, int instr)
{
	int i;

	i = 0;
	if (instr == 0 || instr == 2)
	{
		while (arg[i])
		{
			free(arg[i]);
			arg[i] = NULL;
			i++;
		}
		free(arg);
		arg = NULL;
	}
	if (instr == 1 || instr == 2)
		free(*numbers);
	return (0);
}

int			parse_input(int argc, char **argv, t_stack **a)
{
	int		*numbers;
	char	**arg;

	if (argc == 2)
	{
		arg = ft_strsplit(argv[1], ' ');
		argc = count(arg) + 1;
		if (!(numbers = (int*)malloc(sizeof(int) * (argc - 1))))
			return (free_all(arg, &numbers, 0));
		if (!(incoming(argc - 1, arg, numbers)))
			return (free_all(arg, &numbers, 2));
		free_all(arg, &numbers, 0);
	}
	else if (argc > 2)
	{
		if (!(numbers = (int*)malloc(sizeof(int) * (argc - 1))))
			return (0);
		if (!(incoming(argc - 1, argv + 1, numbers)))
			return (free_all(NULL, &numbers, 1));
	}
	else
		return (0);
	*a = create_stack(numbers, argc - 1, 0);
	free(numbers);
	return (1);
}
