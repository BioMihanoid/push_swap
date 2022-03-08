/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:22:56 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	copy_arr(int *num, int *num1, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		num1[i] = num[i];
		i++;
	}
	return (*num1);
}

int	bubl_sort_arr(int *num, int size)
{
	int			j;
	int			i;
	int			t;

	if (!num || !size)
		return (0);
	i = 0;
	t = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (num[j - 1] > num[j])
			{
				t = num[j - 1];
				num[j - 1] = num[j];
				num[j] = t;
			}
			j--;
		}
		i++;
	}
	return (*num);
}

int	get_index_for_chr(int *num, int nbr)
{
	int	i;

	i = 0;
	while (num[i] != nbr)
		i++;
	return (i);
}

int	min_range(t_stack **a)
{
	int		i;
	t_stack	*t;

	t = *a;
	i = t->index;
	while (t != NULL)
	{
		if (i > t->index)
			i = t->index;
		t = t->next;
	}
	return (i);
}

int	max_range(t_stack **a)
{
	int		i;
	t_stack	*t;

	t = *a;
	i = t->index;
	while (t != NULL)
	{
		if (i < t->index)
			i = t->index;
		t = t->next;
	}
	return (i);
}
