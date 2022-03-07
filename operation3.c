/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:31:38 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int info)
{
	t_stack	*t1;
	t_stack	*t2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	t1 = *stack_a;
	t2 = *stack_a;
	*stack_a = (*stack_a)->next;
	while (t1->next)
		t1 = t1->next;
	t1->next = t2;
	t2->next = NULL;
	if (info)
		printf("ra\n");
}

void	rb(t_stack **stack_b, int info)
{
	t_stack	*t1;
	t_stack	*t2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	t1 = *stack_b;
	t2 = *stack_b;
	*stack_b = (*stack_b)->next;
	while (t1->next)
		t1 = t1->next;
	t1->next = t2;
	t1->next->next = NULL;
	if (info)
		printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	printf("rr\n");
}