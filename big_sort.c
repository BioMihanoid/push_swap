/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:40:33 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:17 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	copy_stack_b(t_stack *b, int *num)
{
	int	d;

	if (!b || !num)
		return (0);
	d = 0;
	while (b)
	{
		num[d] = b->index;
		b = b->next;
		d++;
	}
	return (*num);
}

int	eq_src(t_stack **a, int med, int i)
{
	int		z;
	int		*num;

	num = malloc(sizeof(int) * (i + 1));
	if (!num)
		return (0);
	*num = copy_stack_b(*a, num);
	z = i;
	while (num[i] != med)
		i--;
	z = z - i;
	i = 0;
	while (num[i] != med)
		i++;
	free(num);
	if (z < i)
		return (1);
	return (0);
}

void	return_value_in_stack_a(t_stack **a, t_stack **b)
{
	while ((*b) != NULL)
	{
		if ((*b)->index != max_range(b) && !eq_src(b, max_range(b),
				stack_size(*b)))
			rb(b, 1);
		else if ((*b)->index != max_range(b) && eq_src(b, max_range(b),
				stack_size(*b)))
			rrb(b, 1);
		else if ((*b)->index == max_range(b))
			pa(a, b);
	}
}

void	sort_100_nbr(t_stack **a, t_stack **b)
{
	int	l;

	l = 0;
	while ((*a) != NULL)
	{
		if (l > 1 && (*a)->index <= l)
		{
			pb(a, b);
			l++;
			rb(b, 1);
		}
		else if ((*a)->index <= l + 15)
		{
			pb(a, b);
			l++;
		}
		else if ((*a)->index >= l)
			ra(a, 1);
	}
	return_value_in_stack_a(a, b);
}

void	sort_500_nbr(t_stack **a, t_stack **b)
{
	int	l;

	l = 0;
	while ((*a) != NULL)
	{
		if (l > 1 && (*a)->index <= l)
		{
			pb(a, b);
			l++;
			rb(b, 1);
		}
		else if ((*a)->index <= l + 30)
		{
			pb(a, b);
			l++;
		}
		else if ((*a)->index >= l)
			ra(a, 1);
	}
	return_value_in_stack_a(a, b);
}
