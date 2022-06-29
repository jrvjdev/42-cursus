/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:56:48 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 11:16:01 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%i\n", stack->content);
		stack = stack->next;
	}
}
