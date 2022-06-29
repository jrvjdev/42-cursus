/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:38 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 00:17:03 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/player.h"

static void	draw(void)
{
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->sprites, \
		(*object(Last))->position.x, (*object(Last))->position.y);
}

static void	update(void)
{
	if (key()->a && !key()->d)
		set_animation(left);
	else if (key()->d && !key()->a)
		set_animation(right);
	else if (key()->w && !key()->s)
		set_animation(up);
	else if (key()->s && !key()->w)
		set_animation(down);
	if (key()->s || key()->w || key()->a || key()->d)
		map()->steps++;
	translate(new_vector2((key()->d - key()->a) * 4, \
	(key()->s - key()->w) * 4));
	if ((*object(Last))->collided && (*object(Last))->collided->type == \
	'C')
	{
		destroy_object((*object(Last))->collided);
		(*object(Last))->collectible++;
	}
	(*object(Last))->collided = NULL;
}

static void	set_collision_types(t_object **ob)
{
	(*ob)->collision_types[0] = 'C';
	(*ob)->collision_types[1] = 'E';
}

void	new_player(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = 'P';
	ob->collider = new_collider(7, 37, 29, 52);
	sprite = new_sprite(file_name);
	vector2 = new_vector2(4, 4);
	set_collision_types(&ob);
	ob->animator.size = 5;
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, "0");
	ob->animator.animation[down] = new_animation(10, sprite, vector2, \
	"0,1,2,3");
	ob->animator.animation[left] = new_animation(10, sprite, vector2, \
	"4,5,6,7");
	ob->animator.animation[right] = new_animation(10, sprite, vector2, \
	"8,9,10,11");
	ob->animator.animation[up] = new_animation(10, sprite, vector2, \
	"12,13,14,15");
	ob->animator.state = idle;
	ob->sprites = ob->animator.animation[idle].frames[0];
	destroy_sprite(&sprite);
	ob->update = update;
	ob->draw = draw;
}
