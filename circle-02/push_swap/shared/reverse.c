/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:44:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/11 19:53:54 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, int option)
{
	t_list	*temp;
	t_list	*new_end;

	temp = *stack;
	temp = lst_last(temp);
	temp->next = *stack;
	new_end = *stack;
	while (new_end->next != temp)
		new_end = new_end->next;
	new_end->next = NULL;
	*stack = temp;
	if (option == 1)
		write(1, "rra\n", 4);
	if (option == 2)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int option)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (option == 0)
		write(1, "rrr\n", 4);
}
