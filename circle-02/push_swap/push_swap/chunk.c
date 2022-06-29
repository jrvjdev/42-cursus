/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:03:17 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 14:04:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if the list element is in the chunk
int	exist_chunk(t_list *stack_a, t_chunk ch)
{
	while (stack_a)
	{
		if (stack_a->content >= ch.min_value \
		&& stack_a->content <= ch.max_value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

//advance to the next chunk
void	increment_chunk(t_chunk *chunk, int *list, int length, int option)
{
	if (option == 1)
	{
		chunk->index_min = 0;
		chunk->index_max = length;
	}
	else
	{
		chunk->index_min += length;
		chunk->index_max = chunk->index_min + length;
	}
	chunk->min_value = list[chunk->index_min];
	chunk->max_value = list[chunk->index_max];
}

//push the chunck to stack b
void	push_chunk(t_list **stack_a, t_list **stack_b, \
t_chunk chunck, int chunk_amount)
{
	if (*stack_a)
	{
		if ((*stack_a)->content >= chunck.min_value \
		&& (*stack_a)->content <= chunck.max_value)
			push(stack_a, stack_b, 1);
		else
		{
			if (chunk_amount == 2)
			{
				push(stack_a, stack_b, 1);
				rotate(stack_b, 2);
			}
			else
				rotate(stack_a, 1);
		}
	}
}
