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

void    sort_3_nbr(t_stack **a)
{
	if ((*a)->index == max_range(a))
		ra(a, 1);
	if ((*a)->index == min_range(a) && (*a)->next->index == max_range(a))
	{
		rra(a, 1);
		sa(a, 1);
	}
	if ((*a)->index != min_range(a) && (*a)->index > (*a)->next->index)
		sa(a, 1);
	if ((*a)->index != min_range(a) && (*a)->index < (*a)->next->index)
		rra(a, 1);
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
	int max;
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

void    mini_sort(t_stack **a, t_stack **b, int size)
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

