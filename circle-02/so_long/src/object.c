/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:46:14 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 23:17:20 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/object.h"

t_object	**object(t_option option)
{
	static t_object	*first;
	static t_object	*last;

	if (option == Last)
		return (&last);
	else
		return (&first);
}

void	add_object(t_object **new_object)
{
	if (!(*object(First)))
		(*object(First)) = (*new_object);
	else
	{
		(*object(1)) = (*object(First));
		while ((*object(Last))->next)
			(*object(Last)) = (*object(Last))->next;
		(*new_object)->prev = (*object(Last));
		(*object(Last))->next = (*new_object);
	}
	(*object(Last)) = (*new_object);
}

void	destroy_object(t_object *_object)
{
	int				i;
	int				j;

	i = -1;
	j = -1;
	if (!_object)
		return ;
	while (++i < _object->animator.size)
	{
		while (++j < _object->animator.animation->size)
			mlx_destroy_image(program()->mlx_ptr, \
			_object->animator.animation[i].frames[j]);
		j = -1;
	}
	if (_object->collider)
		free_maloc(_object->collider);
	if (_object->prev && _object->next)
	{
		_object->prev->next = _object->next;
		_object->next->prev = _object->prev;
	}
	else if (!_object->prev)
		(*object(First)) = (*object(First))->next;
	free_maloc(_object);
	(program())->amount_objs--;
}

void	destroy_all_object(void)
{
	while ((*object(First)))
	{
		(*object(Last)) = (*object(First));
		(*object(First)) = (*object(First))->next;
		destroy_object((*object(Last)));
	}
	if (window()->win_ptr)
		mlx_destroy_window(program()->mlx_ptr, window()->win_ptr);
	exit(0);
}

t_object	*new_object(t_vector2 position)
{
	t_object		*object;
	t_vector2		vector;

	object = new_maloc(sizeof(*object));
	object->position = position;
	object->collision_types[0] = 'X';
	object->collision_types[1] = 'X';
	object->collision_types[2] = 'X';
	object->collision_types[3] = 'X';
	object->data = NULL;
	object->prev = NULL;
	object->next = NULL;
	object->draw = NULL;
	object->update = NULL;
	object->sprites = NULL;
	object->collider = NULL;
	object->collectible = 0;
	vector = new_vector2(-1, -1);
	while (++vector.x < 5)
		while (++vector.y < 12)
			object->animator.animation[vector.x].frames[vector.y] = NULL;
	add_object(&object);
	program()->amount_objs++;
	object->layer = 1;
	return (object);
}
