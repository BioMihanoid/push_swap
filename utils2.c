/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:30:08 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:18 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

t_stack	*stack_new_item(int content)
{
	t_stack	*new_item;

	new_item = malloc(sizeof(t_stack));
	if (!new_item)
		return (NULL);
	new_item->nbr = content;
	new_item->next = NULL;
	return (new_item);
}

void	stack_new_item_in_back(t_stack **lst, t_stack *new)
{
	t_stack	*t_elm;

	t_elm = *lst;
	if (lst)
	{
		if (*lst)
		{
			while (t_elm->next)
				t_elm = t_elm->next;
			t_elm->next = new;
		}
		else
			*lst = new;
	}
}

int    stack_to_array(t_stack *b, int *num)
{
    int i;

    if (!b || !num)
        return (0);
    i = 0;
    while (b)
    {
        num[i] = b->nbr;
        b = b->next;
        i++;
    }
    return (*num);
}

void    get_index(t_stack **a, int size)
{
    t_stack *b;
    t_stack *z;
    int     i;
    int     *num;
    int     *num1;

    i = 0;
    b = *a;
    z = b;
    num = malloc(sizeof(int) * (size + 1));
    num1 = malloc(sizeof(int) * (size + 1));
    if (!num || !num1)
        return ;
    *num = stack_to_array(b, num);
	*num1 = copy_arr(num, num1, size);
	*num = bubl_sort_arr(num, size);
	while (z != NULL)
	{
		z->index = get_index_for_chr(num, num1[i]);
		z = z->next;
		i++;
	}
	free(num);
	free(num1);
}
