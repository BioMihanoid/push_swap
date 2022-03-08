/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:23 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	get_value_stack_a(t_stack **stack_a, int *a, int *b, int *c)
{
	*a = (*stack_a)->nbr;
	*b = (*stack_a)->next->nbr;
	*c = (*stack_a)->next->next->nbr;
}

void	sort_3_nbr(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	get_value_stack_a(stack_a, &a, &b, &c);
	if (a > b && b < c && c < a)
		ra(stack_a, 1);
	else if (a > b && b < c && c > a)
		sa(stack_a, 1);
	else if (a < b && b > c && c < a)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && c > a)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
}

void	sort_4_nbr(t_stack **a, t_stack **b)
{
	int	min;

	min = search_min(*a);
	while (stack_size(*a) != 3)
	{
		if ((*a)->nbr != min)
			ra(a, 1);
		else
			pb(a, b);
	}
	if (!a_is_sorted(*a))
		sort_3_nbr(a);
	pa(a, b);
}

void	sort_5_nbr(t_stack **a, t_stack **b)
{
	int	max;
	int	min;

	min = search_min(*a);
	max = search_max(*a);
	while (stack_size(*a) != 3)
	{
		if ((*a)->nbr != min && (*a)->nbr != max)
			ra(a, 1);
		else
			pb(a, b);
	}
	if (!a_is_sorted(*a))
		sort_3_nbr(a);
	if ((*b)->nbr < (*b)->next->nbr)
		sb(b, 1);
	pa(a, b);
	ra(a, 1);
	pa(a, b);
}

void	mini_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a, 1);
	if (size == 3)
		sort_3_nbr(a);
	if (size == 4)
		sort_4_nbr(a, b);
	if (size == 5)
		sort_5_nbr(a, b);
}
