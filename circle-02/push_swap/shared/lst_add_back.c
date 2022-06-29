/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:44:44 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/11 21:04:03 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	lst_add_back(t_list **lst, t_list *new)
// {
// 	if (lst)
// 		lst_last(*lst)->next = new;
// }

void	lst_add_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		lst_last(*lst)->next = new;
}
