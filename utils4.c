/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:11:25 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int search_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int search_min(t_stack *stack)
{
	int min;

	if (!stack)
		return (0);
	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	ft_help_result(int check_sign)
{
	if (!check_sign)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					check_sign;
	unsigned long long	res;
	int					count_number;

	i = 0;
	check_sign = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			check_sign = 1;
	count_number = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (count_number > 19 && check_sign)
			return (0);
		if (count_number++ > 19)
			return (-1);
		res = res * 10 - (str[i] - '0');
		i++;
	}
	return (res * ft_help_result(check_sign));
}