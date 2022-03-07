/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:31:16 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int info)
{
	t_stack	*t;
	t_stack	*t2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	t = stack_last(*stack_a);
	t2 = *stack_a;
	while (t2->next != t)
		t2 = t2->next;
	t->next = *stack_a;
	*stack_a = t;
	t2->next = NULL;
	if (info)
		printf ("rra\n");
}

void	rrb(t_stack **stack_b, int info)
{
	t_stack	*t;
	t_stack	*t2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	t = stack_last(*stack_b);
	t2 = *stack_b;
	while (t2->next != t)
		t2 = t2->next;
	t->next = *stack_b;
	*stack_b = t;
	t2->next = NULL;
	if (info)
		printf ("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	printf ("rrr\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*t;

	if (!*stack_b)
		return ;
	t = *stack_b;
	*stack_b = t->next;
	t->next = *stack_a;
	*stack_a = t;
	printf ("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*t;

	if (!*stack_a)
		return ;
	t = *stack_a;
	*stack_a = t->next;
	t->next = *stack_b;
	*stack_b = t;
	printf("pb\n");
}