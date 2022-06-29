/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lts_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:41:57 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/10 18:47:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	lst_add_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
