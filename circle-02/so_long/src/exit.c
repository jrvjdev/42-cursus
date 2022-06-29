/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:11:09 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 00:19:18 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/exit.h"

static void	draw(void)
{
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->sprites, \
		(*object(Last))->position.x, (*object(Last))->position.y);
}

static void	update(void)
{
	static int	open;

	if (!open && (*object(Last))->collided)
	{
		if ((*object(Last))->collided->type == 'P')
		{
			if ((*object(Last))->collided->collectible == map()->collectible)
				open = 1;
		}
	}
	if (open)
	{
		set_animation(up);
		if ((*object(Last))->animator.animation[(*object(Last))->\
		animator.state].index >= (*object(Last))->animator.\
		animation[(*object(Last))->animator.state].size - 1)
			open = -1;
	}
	if (open == -1 && (*object(Last))->collided && (*object(Last))->\
	collided->type == 'P')
	{
		destroy_all_object();
	}
	(*object(Last))->collided = NULL;
}

void	new_exit(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = 'E';
	ob->collider = new_collider(10, 50, 80, 90);
	sprite = new_sprite(file_name);
	vector2 = new_vector2(3, 4);
	ob->animator.size = 2;
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, "1");
	ob->animator.animation[up] = new_animation(10, sprite, vector2, \
	"1,4,7,10,10");
	ob->animator.animation[up].loop = false;
	ob->animator.state = up;
	ob->sprites = ob->animator.animation[up].frames[0];
	destroy_sprite(&sprite);
	ob->update = update;
	ob->draw = draw;
}
