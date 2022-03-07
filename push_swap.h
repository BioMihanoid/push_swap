/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:22:24 by gmilan            #+#    #+#             */
/*   Updated: 2022/03/07 16:51:26 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> // убрать нахуй

typedef struct s_stack
{
	int 			nbr;
	int 			index;
	struct s_stack	*next;
}	t_stack;

void			sa(t_stack **stack_a, int info);
void			sb(t_stack **stack_b, int info);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **stack_a, int info);
void			rb(t_stack **stack_b, int info);
void			rr(t_stack **stack_a, t_stack **stack_b);
void			rra(t_stack **stack_a, int info);
void			rrb(t_stack **stack_b, int info);
void			rrr(t_stack **stack_a, t_stack **stack_b);
int				stack_size(t_stack *stack);
t_stack			*stack_last(t_stack *stack);
int				 a_is_sorted(t_stack *stack);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
long long int	atoi_long_long(char *s);
int				ft_isdigit(char c);
t_stack			*stack_new_item(int content);
void			stack_new_item_in_back(t_stack **lst, t_stack *new);
void			validation(int argc, char **argv, t_stack **stack_a);
int             copy_arr(int *num, int *num1, int size);
int				bubl_sort_arr(int *num, int size);
int				get_index_for_chr(int *num, int nbr);
void		    mini_sort(t_stack **a, t_stack **b, int size);
void			sort_100_nbr(t_stack **a, t_stack **b);
void			sort_500_nbr(t_stack **a, t_stack **b);
int				min_range(t_stack **a);
int				max_range(t_stack **a);
void 		    get_index(t_stack **a, int size);
int			 	search_max(t_stack *stack);
int			 	search_min(t_stack *stack);
int			    stack_to_array(t_stack *b, int *num);
void			return_value_in_stack_a(t_stack **a, t_stack **b);
#endif
