/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:31:31 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int info)
{
	int t;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	t = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = t;
	if (info)
		printf ("sa\n");
}

void	sb(t_stack **stack_b, int info)
{
	int t;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	t = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = t;
	if (info)
		printf ("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
}