/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:56:51 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 21:48:26 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/hook.h"

int	key_down(int keycode)
{
	if (keycode == ESC)
		key()->esc = 1;
	if (keycode == W)
		key()->w = 1;
	if (keycode == S)
		key()->s = 1;
	if (keycode == A)
		key()->a = 1;
	if (keycode == D)
		key()->d = 1;
	return (0);
}

int	key_up(int keycode)
{
	if (keycode == ESC)
		key()->esc = 0;
	if (keycode == W)
		key()->w = 0;
	if (keycode == S)
		key()->s = 0;
	if (keycode == A)
		key()->a = 0;
	if (keycode == D)
		key()->d = 0;
	return (0);
}

t_object	*get_bigger_y(t_object *object)
{
	t_object	*temp;

	temp = object->next;
	while (temp)
	{
		if (object->layer == program()->layer)
			object = object->next;
		if (temp->layer != program()->layer)
			if (object->position.y + object->collider->h > \
			temp->position.y + temp->collider->h)
				object = temp;
		temp = temp->next;
	}
	return (object);
}

int	loop_hook(void)
{
	if (key()->esc)
		destroy_all_object();
	program()->layer *= -1;
	program()->amount_draw = 0;
	while ((program()->amount_draw <= program()->amount_objs))
	{
		(*object(Last)) = get_bigger_y((*object(First)));
		if ((*object(Last))->update)
			(*object(Last))->update();
		if ((*object(Last))->draw)
			(*object(Last))->draw();
		(*object(Last))->layer = program()->layer;
		program()->amount_draw++;
	}
	return (0);
}
