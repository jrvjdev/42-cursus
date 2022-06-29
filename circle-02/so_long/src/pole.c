/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pole.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:21:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 23:07:55 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pole.h"

static void	draw(void)
{
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->sprites, \
		(*object(Last))->position.x, (*object(Last))->position.y);
}

void	new_pole(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = '1';
	ob->collider = new_collider(1, 40, 21, 50);
	vector2 = new_vector2(1, 1);
	sprite = new_sprite(file_name);
	ob->animator.size = 1;
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, "0");
	ob->sprites = ob->animator.animation[idle].frames[0];
	ob->draw = draw;
	destroy_sprite(&sprite);
}
