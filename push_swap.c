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

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int 	size;

	validation(argc, argv, &a);
	size = stack_size(a);
	get_index(&a, size);
	if (a_is_sorted(a))
		exit(EXIT_SUCCESS);
	if (size <= 5)
		mini_sort(&a,& b, size);
	else if (size <= 100)
		sort_100_nbr(&a, &b);
	else
		sort_500_nbr(&a,& b);
	exit(EXIT_SUCCESS);
}