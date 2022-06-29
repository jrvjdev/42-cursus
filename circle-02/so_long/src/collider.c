/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:10:49 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 23:16:01 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/collider.h"

int	col_x(t_object *a, t_object *b, int x)
{
	if (a->position.y + a->collider->y > b->position.y + b->collider->h)
		return (0);
	if (a->position.y + a->collider->h < b->position.y + b->collider->y)
		return (0);
	if (x <= 0)
		if (a->position.x + x + a->collider->x >= b->position.x + \
			b->collider->x)
			if (a->position.x + x + a->collider->x <= b->position.x \
			+ b->collider->w)
				return (1);
	if (x >= 0)
		if (a->position.x + x + a->collider->w >= b->position.x \
		+ b->collider->x)
			if (a->position.x + x + a->collider->w <= b->\
			position.x + b->collider->w)
				return (1);
	if (a->position.x + x + a->collider->x >= b->position.x + b->collider->x)
		if (a->position.x + a->collider->w <= b->position.x + b->collider->w)
			return (1);
	if (a->position.x + x + a->collider->x <= b->position.x + b->collider->x)
		if (a->position.x + a->collider->w >= b->position.x + b->collider->w)
			return (1);
	return (0);
}

int	col_y(t_object *a, t_object *b, int y)
{
	if (a->position.x + a->collider->x > b->position.x + b->collider->w)
		return (0);
	if (a->position.x + a->collider->w < b->position.x + b->collider->x)
		return (0);
	if (y <= 0)
		if (a->position.y + y + a->collider->y >= b->position.y + \
			b->collider->y)
			if (a->position.y + y + a->collider->y <= b->position.y \
			+ b->collider->h)
				return (1);
	if (y >= 0)
		if (a->position.y + y + a->collider->h >= b->position.y \
		+ b->collider->y)
			if (a->position.y + y + a->collider->h <= \
			b->position.y + b->collider->h)
				return (1);
	if (a->position.y + y + a->collider->y >= b->position.y + b->collider->y)
		if (a->position.y + a->collider->h <= b->position.y + b->collider->h)
			return (1);
	if (a->position.y + y + a->collider->y <= b->position.y + b->collider->y)
		if (a->position.y + a->collider->h >= b->position.y + b->collider->h)
			return (1);
	return (0);
}

t_bool	check_type(t_object *cursor)
{
	int	i;

	i = -1;
	while (++i < 4)
		if ((*object(Last))->collision_types[i] == cursor->type)
			return (1);
	return (0);
}

void	check_collision(t_object *cursor, t_vector2 *translate, t_vector2 v)
{
	cursor = (*object(First));
	while (cursor)
	{
		if ((*object(Last)) != cursor && cursor->collider)
		{
			v.x = col_x((*object(Last)), cursor, translate->x);
			v.y = col_y((*object(Last)), cursor, translate->y);
			if (v.x && !cursor->collider->trigger && !(*object(Last))->\
			collider->trigger)
				translate->x = 0;
			if (v.y && !cursor->collider->trigger && !(*object(Last))->\
			collider->trigger)
				translate->y = 0;
			if ((v.x || v.y) && check_type(cursor))
			{
				cursor->collided = (*object(Last));
				(*object(Last))->collided = cursor;
			}
		}
		cursor = cursor->next;
	}
}

t_collider	*new_collider(int x, int y, int w, int h)
{
	t_collider	*collider;

	collider = new_maloc(sizeof(t_collider));
	collider->trigger = false;
	collider->x = x;
	collider->y = y;
	collider->w = w;
	collider->h = h;
	return (collider);
}
