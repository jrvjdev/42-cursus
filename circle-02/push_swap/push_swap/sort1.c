/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:43:56 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/11 20:58:08 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort1(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a < b && b > c && a < c)
	{
		reverse_rotate(stack_a, 1);
		swap(stack_a, 1);
	}
	else if (a > b && b < c && a < c)
		swap(stack_a, 1);
	else if (a < b && b > c && a > c)
		reverse_rotate(stack_a, 1);
	else if (a > b && b > c && c < a)
	{
		rotate(stack_a, 1);
		swap(stack_a, 1);
	}
	else
		rotate(stack_a, 1);
}
