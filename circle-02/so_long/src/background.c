/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:55:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 20:48:38 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/background.h"

void	draw(void)
{
	t_vector2			vector;

	vector = new_vector2(0, 0);
	while (1)
	{
		mlx_put_image_to_window(program()->mlx_ptr, window()->win_ptr, \
		(*object(Last))->animator.animation[0].frames[0], vector.x, \
		vector.y);
		if (vector.x >= window()->size.x)
		{
			vector.x = 0;
			vector.y += 64;
			if (vector.y >= window()->size.y)
				break ;
		}
		else
			vector.x += 64;
	}
}

void	new_background(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = Scenery;
	ob->collider = new_collider(-10, -10, -10, -10);
	sprite = new_sprite(file_name);
	vector2 = new_vector2(3, 2);
	ob->animator.size = 1;
	ob->animator.animation[idle] = new_animation(0, sprite, vector2, \
	"0");
	ob->animator.state = idle;
	ob->sprites = ob->animator.animation[idle].frames[0];
	destroy_sprite(&sprite);
	ob->draw = draw;
}
