/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:43:45 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 11:16:36 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, int option)
{
	t_list	*cursor;
	t_list	*new_start;

	cursor = lst_last(*stack);
	cursor->next = *stack;
	cursor = *stack;
	new_start = (*stack)->next;
	cursor->next = NULL;
	*stack = new_start;
	if (option == 1)
		write(1, "ra\n", 3);
	if (option == 2)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int option)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (option == 0)
		write(1, "rr\n", 3);
}
