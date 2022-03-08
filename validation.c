/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:14:22 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	arg_check(char *s)
{
	int				i;
	long long int	t;
	int				flag;

	if (!*s)
		return (1);
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-' && !ft_isspace(s[i]))
			return (1);
		if (flag && s[i] == '-')
			return (1);
		if (!flag && s[i] == '-')
			flag = 1;
		i++;
	}
	if (flag && ft_strlen(s) == 1)
		return (1);
	t = atoi_long_long(s);
	if (t < INT_MIN || t > INT_MAX || ft_atoi(s + i))
		return (1);
	return (0);
}

void	check_dublicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error();
			j++;
		}
		i++;
	}
}

void	add_item_in_stack(char *s, t_stack **stack_a)
{
	if (!*stack_a)
		*stack_a = stack_new_item(ft_atoi(s));
	else
		stack_new_item_in_back(stack_a, stack_new_item(ft_atoi(s)));
}

void	validation(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	if (argc < 2)
		error();
	else if (argc == 2)
		check_split_arg(argv[1], stack_a);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (arg_check(argv[i]))
				error();
			if (check_count_nbr(argv[i]))
				error();
			i++;
		}
		check_dublicate(argc, argv);
		i = 1;
		while (i < argc)
			add_item_in_stack(argv[i++], stack_a);
	}
}
