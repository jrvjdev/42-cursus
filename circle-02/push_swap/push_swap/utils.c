/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:46:40 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 13:52:26 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	step_amounts(t_list *stack_a, t_list *stack_b, \
t_list *spot, t_list *cursor)
{
	if (ft_cost_r(stack_b, cursor) > ft_cost_rr(cursor))
	{
		if (ft_cost_r(stack_a, spot) > ft_cost_rr(spot))
			return (ft_cost_rr(cursor) + ft_cost_rr(spot));
		else
			return (ft_cost_rr(cursor) + \
			ft_cost_r(stack_a, spot));
	}
	if (ft_cost_r(stack_a, spot) > ft_cost_rr(spot))
		return (ft_cost_r(stack_b, cursor) + ft_cost_rr(spot));
	else
		return (ft_cost_r(stack_b, cursor) + \
		ft_cost_r(stack_a, spot));
}

//returns the best item in the list
t_list	*best_element(t_list *stack_a, t_list *stack_b)
{
	t_list	*cursor_stack;
	t_list	*spot_stack;
	t_list	*cursor_best;
	t_list	*spot_best;

	cursor_stack = stack_b;
	cursor_best = stack_b;
	spot_best = find_spot(stack_a, cursor_best);
	while (cursor_stack)
	{
		spot_stack = find_spot(stack_a, cursor_stack);
		if (step_amounts(stack_a, stack_b, spot_stack, cursor_stack) \
		< step_amounts(stack_a, stack_b, spot_best, cursor_best))
		{
			cursor_best = cursor_stack;
			spot_best = spot_stack;
		}
		cursor_stack = cursor_stack->next;
	}
	return (cursor_best);
}

//checks whether both stacks need to be rotated or reverse rotated
void	join_moves(t_list **stack_a, t_list **stack_b, \
t_list *spot, t_list *best)
{
	if (*stack_a != best && *stack_b != spot)
	{
		if (ft_cost_r(*stack_b, spot) > ft_cost_rr(spot))
		{
			if (ft_cost_r(*stack_a, best) > ft_cost_rr(best))
				rrr(stack_a, stack_b, 0);
		}
		else
		{
			if (ft_cost_r(*stack_a, best) < ft_cost_rr(best))
				rr(stack_a, stack_b, 0);
		}
	}
}
