/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:04:12 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 00:31:16 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/enemy.h"

static void	draw(void)
{
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->sprites, \
		(*object(Last))->position.x, (*object(Last))->position.y);
}

void	guard(void)
{
	static int	i = 0;

	if (i++ > 1000)
		i = 0;
	if ((i > 500) - (i < 500) > 0)
		set_animation(right);
	else
		set_animation(left);
	(*object(Last))->collider->trigger = true;
	(*object(Last))->collision_types[0] = 'P';
	(*object(Last))->collider = new_collider(-157, -127, 156, 202);
	translate(new_vector2(0, 0));
	(*object(Last))->collider->trigger = false;
	(*object(Last))->collider = new_collider(7, 37, 29, 52);
	translate(new_vector2((i > 500) - (i < 500), 0));
}

static void	set_direction(void)
{
	translate(new_vector2(\
	(((*object(Last))->data->position.x > (*object(Last))->position.x) - \
	((*object(Last))->data->position.x < (*object(Last))->position.x)) * 2, \
	(((*object(Last))->data->position.y > (*object(Last))->position.y) - \
	((*object(Last))->data->position.y < (*object(Last))->position.y)) * 2 \
	));
}

static void	update(void)
{
	if (!(*object(Last))->collided && !(*object(Last))->data)
		guard();
	else
	{
		if ((*object(Last))->collided && (*object(Last))->data)
			destroy_all_object();
		if (!(*object(Last))->data && (*object(Last))->collided && \
		(*object(Last))->collided->type == 'P')
			(*object(Last))->data = (*object(Last))->collided;
		(*object(Last))->collided = NULL;
		if ((*object(Last))->data)
		{
			if (((*object(Last))->data->position.x + 5 < (*object(Last))->\
			position.x) - ((*object(Last))->data->position.x - 5 > \
			(*object(Last))->position.x) < 0)
				set_animation(right);
			if (((*object(Last))->data->position.x > (*object(Last))->\
			position.x) - ((*object(Last))->data->position.x < (*object(Last))->\
			position.x) < 0)
				set_animation(left);
			set_direction();
		}
	}
}

void	new_enemy(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = '0';
	ob->collider = new_collider(-127, -97, 126, 172);
	sprite = new_sprite(file_name);
	vector2 = new_vector2(4, 4);
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
