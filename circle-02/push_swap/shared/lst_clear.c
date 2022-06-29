/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:44:50 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 19:42:33 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		lst_delone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	lst_clear_all(t_list **lst_a, t_list **lst_b)
{
	lst_clear(lst_a);
	lst_clear(lst_b);
}
