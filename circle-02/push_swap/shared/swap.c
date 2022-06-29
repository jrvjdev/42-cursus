/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:46:26 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/02 21:41:20 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int option)
{
	int		temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (option == 1)
		write(1, "sa\n", 3);
	if (option == 2)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int option)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (option == 0)
		write(1, "ss\n", 3);
}
