/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:57:21 by joaribei          #+#    #+#             */
/*   Updated: 2022/02/21 16:59:14 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vector2.h"

t_vector2	new_vector2(int x, int y)
{
	t_vector2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}
