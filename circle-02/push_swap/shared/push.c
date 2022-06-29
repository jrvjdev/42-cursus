/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:46:12 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/10 18:50:08 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dest, int option)
{
	t_list	*cursor;

	cursor = (*src)->next;
	lst_add_front(dest, (*src));
	(*src) = cursor;
	if (option == 1)
		write(1, "pb\n", 3);
	if (option == 2)
		write(1, "pa\n", 3);
}
