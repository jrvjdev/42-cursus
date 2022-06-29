/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:46:33 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 19:56:18 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "shared.h"

/*
* structs
*/
typedef struct s_chunk
{
	int		min_value;
	int		max_value;
	int		index_min;
	int		index_max;
}			t_chunk;

void	print_list(t_list *stack);

void	sort1(t_list **stack_a);
void	sort2(t_list **stack_a, t_list **stack_b, int ac);
void	sort3(t_list **stack_a, int ac);
void	join_moves(t_list **stack_a, t_list **stack_b, \
t_list *spot, t_list *best);

int		lst_sorted(t_list *stack_a);
int		have_errors(int ac, char **av, int op);
int		have_duplicates(t_list *list);

//chuck's functions
int		exist_chunk(t_list *stack_a, t_chunk ch);
void	push_chunk(t_list **stack_a, t_list **stack_b, \
t_chunk chunck, int chunk_amount);
void	increment_chunk(t_chunk *chunk, int *list, int length, int option);

//functions that check best possibilities
int		ft_cost_rr(t_list *spot);
int		ft_cost_r(t_list *stack, t_list *spot);
t_list	*lst_biggest_element(t_list *stack_a);
t_list	*lts_smaller_element(t_list *stack_a);
t_list	*find_spot(t_list *stack_a, t_list *stack_b);
t_list	*best_element(t_list *stack_a, t_list *stack_b);
int		calculate_steps(t_list *stack_a, t_list *stack_b, t_list *s, t_list *c);

#endif
