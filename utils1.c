/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:33:35 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	a_is_sorted(t_stack *stack)
{
	t_stack	*t;

	t = stack;
	if (!stack || !stack->next)
		return (0);
	while (t->next)
	{
		if (t->nbr > t->next->nbr)
			return (0);
		t = t->next;
	}
	return (1);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f'
		|| c == '\v');
}

long long int	atoi_long_long(char *s)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] && ft_is_space(s[i]))
		i++;
	if (s[i] == '-')
		sign *= -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	if (s[i])
		return (0);
	return (res * sign);
}
