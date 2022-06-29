/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:08:05 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 11:17:04 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **stack_a, int ac)
{
	if (lst_size(lst_biggest_element(*stack_a)) > ac / 2)
		while (!(lst_sorted(*stack_a)))
			rotate(stack_a, 1);
	else
		while (!(lst_sorted(*stack_a)))
			reverse_rotate(stack_a, 1);
}
