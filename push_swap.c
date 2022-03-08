/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:30 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	validation(argc, argv, &a);
	if (a_is_sorted(a))
		exit(EXIT_SUCCESS);
	size = stack_size(a);
	get_index(&a, size);
	if (size <= 5)
		mini_sort(&a, &b, size);
	else if (size <= 100)
		sort_100_nbr(&a, &b);
	else
		sort_500_nbr(&a, &b);
	if (a)
		stack_clear(&a);
	if (b)
		stack_clear(&b);
	exit(EXIT_SUCCESS);
}
