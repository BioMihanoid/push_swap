/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:35 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/08 18:21:58 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_split_duplication(int length, char **split_result)
{
	int	i;
	int	j;

	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (ft_atoi(split_result[i]) == ft_atoi(split_result[j]))
				error();
			j++;
		}
		i++;
	}
}

static int	split_arg_length(char **split_result)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (split_result[i])
	{
		counter++;
		i++;
	}
	return (counter);
}

static void	fill_split_arg(char **split_result, int length, t_stack **a)
{
	int	i;

	i = 0;
	while (i < length)
	{
		add_item_in_stack(split_result[i], a);
		i++;
	}
	i = length - 1;
	while (i >= 0)
		free(split_result[i--]);
	free(split_result);
}

void	check_split_arg(char *arg, t_stack **a)
{
	char	**split_result;
	int		i;
	int		length;

	split_result = ft_split(arg);
	if (!split_result)
		error();
	length = split_arg_length(split_result);
	i = 0;
	while (i < length)
	{
		if (arg_check(split_result[i++]))
			error();
	}
	if (length < 2)
		exit (EXIT_SUCCESS);
	check_split_duplication(length, split_result);
	fill_split_arg(split_result, length, a);
}

int	check_count_nbr(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (!s[i])
		return (0);
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (0);
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	if (!s[i])
		return (0);
	if (s[i] && ft_isdigit(s[i]))
		return (1);
	return (0);
}
