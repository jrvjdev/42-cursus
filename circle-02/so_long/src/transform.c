/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:10:09 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 02:59:37 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/transform.h"

void	translate(t_vector2 translate)
{
	check_collision(NULL, &translate, new_vector2(0, 0));
	if (!translate.x && !translate.y)
		return ;
	if (translate.x && translate.y)
		translate.y /= 2;
	program()->moves++;
	(*object(Last))->position.x += translate.x;
	(*object(Last))->position.y += translate.y;
}

void	position(t_vector2 position)
{
	(*object(Last))->position = position;
}
