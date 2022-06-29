/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:44:21 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 13:22:24 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns the biggest element of the stack
t_list	*lst_biggest_element(t_list *stack_a)
{
	t_list	*biggest;

	biggest = stack_a;
	while (stack_a)
	{
		if (stack_a->content > biggest->content)
			biggest = stack_a;
		stack_a = stack_a->next;
	}
	return (biggest);
}

//returns the smallest element of the stack
t_list	*lts_smaller_element(t_list *stack_a)
{
	t_list	*smaller;

	smaller = stack_a;
	while (stack_a)
	{
		if (stack_a->content < smaller->content)
			smaller = stack_a;
		stack_a = stack_a->next;
	}
	return (smaller);
}

//find the best place in stack a to put an item in stack b
t_list	*find_spot(t_list *stack_a, t_list *stack_b)
{
	if (stack_b->content > lst_last(stack_a)->content \
	&& lst_biggest_element(stack_a) == lst_last(stack_a))
		return (stack_a);
	if (stack_b->content < lts_smaller_element(stack_a)->content)
		return (lts_smaller_element(stack_a));
	if (stack_a->content > stack_b->content \
	&& lst_last(stack_a)->content < stack_b->content)
		return (stack_a);
	if (stack_b->content > lst_biggest_element(stack_a)->content)
		return (lst_biggest_element(stack_a)->next);
	while (!(stack_a->content < stack_b->content \
	&& stack_a->next->content > stack_b->content))
		stack_a = stack_a->next;
	while (stack_a->content < stack_b->content)
		stack_a = stack_a->next;
	return (stack_a);
}

//returns the cost of doing a rotate move
int	ft_cost_r(t_list *stack, t_list *spot)
{
	return (lst_size(stack) - lst_size(spot));
}

//returns the cost of doing a reverse rotate move
int	ft_cost_rr(t_list *spot)
{
	return (lst_size(spot));
}
