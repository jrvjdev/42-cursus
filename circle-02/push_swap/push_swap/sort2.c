/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:44:14 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 13:59:43 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorted the list
void	sort_array(int *list, int size)
{
	int	cursor;
	int	temp;

	cursor = --size;
	while (size)
	{
		if (list[cursor] > list[size])
		{
			temp = list[cursor];
			list[cursor] = list[size];
			list[size] = temp;
		}
		if (!cursor)
			cursor = --size;
		else
			cursor--;
	}
}

//create the array to use in thunks
int	*create_array(t_list **stack_a, int size)
{
	int		*array;
	int		index;
	t_list	*cursor;

	array = malloc(size * sizeof(int));
	if (!array)
		exit(write(2, "Error\n", 6));
	cursor = *stack_a;
	index = 0;
	while (cursor)
	{
		array[index++] = cursor->content;
		cursor = cursor->next;
	}
	sort_array(array, size);
	return (array);
}

//return element to stack a
void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*best;
	t_list	*spot;

	best = best_element(*stack_a, *stack_b);
	spot = find_spot(*stack_a, best);
	while (*stack_b != best || *stack_a != spot)
	{
		join_moves(stack_a, stack_b, spot, best);
		while (best != *stack_b)
		{
			if (ft_cost_r(*stack_b, best) > ft_cost_rr(best))
				while (*stack_b != best)
					reverse_rotate(stack_b, 2);
			else
				while (*stack_b != best)
					rotate(stack_b, 2);
		}
		if (ft_cost_r(*stack_a, spot) > ft_cost_rr(spot))
			while (*stack_a != spot)
				reverse_rotate(stack_a, 1);
		else
			while (*stack_a != spot)
				rotate(stack_a, 1);
	}
	push(stack_b, stack_a, 2);
}

//returns the number of chunks
static int	chunks_amounts(int size)
{
	if (size < 100)
		return (1);
	return (size / 100);
}

void	sort2(t_list **stack_a, t_list **stack_b, int ac)
{
	int		*array;
	int		length_chunk;
	int		max;
	t_chunk	chunk;

	length_chunk = lst_size(*stack_a) / chunks_amounts(lst_size(*stack_a));
	array = create_array(stack_a, ac);
	max = lst_size(*stack_a);
	increment_chunk(&chunk, array, length_chunk, 1);
	while (lst_size(*stack_a) > 3)
	{
		if (exist_chunk(*stack_a, chunk))
			push_chunk(stack_a, stack_b, chunk, chunks_amounts(max));
		else
			increment_chunk(&chunk, array, length_chunk, 2);
	}
	free(array);
	if (!lst_sorted(*stack_a))
		sort1(stack_a);
	while (lst_size(*stack_b) > 0)
		push_back(stack_a, stack_b);
	if (!lst_sorted(*stack_a))
		sort3(stack_a, ac);
}
