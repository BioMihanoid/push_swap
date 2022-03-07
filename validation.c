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

int 	arg_check(char *s)
{
	int				i;
	long long int	t;

	if (!*s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-')
			return (1);
		i++;
	}
	t = atoi_long_long(s);
	if (t == 0 || t < INT_MIN || t > INT_MAX)
		return (1);
	return (0);
}

void	check_dublicate(int argc, char **argv)
{
	int	i;
	int j;

	i = 0;
	while (i < argc + 1)
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
	{
		return ;
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (arg_check(argv[i++]))
				error();
		}
		check_dublicate(argc, argv);
		i = 1;
		while (i < argc)
			add_item_in_stack(argv[i++], stack_a);
	}
}