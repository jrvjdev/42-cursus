/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fence.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:09:30 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 23:18:31 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fence.h"

static void	draw(void)
{
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->sprites, \
		(*object(Last))->position.x, (*object(Last))->position.y);
}

void	new_fence_w(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = Fence;
	ob->collider = new_collider(1, 38, 43, 42);
	vector2 = new_vector2(1, 1);
	sprite = new_sprite(file_name);
	ob->animator.size = 1;
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, "0");
	ob->sprites = ob->animator.animation[idle].frames[0];
	ob->draw = draw;
	destroy_sprite(&sprite);
}

void	new_fence_h(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = Fence;
	ob->collider = new_collider(1, 0, 11, 60);
	vector2 = new_vector2(1, 1);
	sprite = new_sprite(file_name);
	ob->animator.size = 1;
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, "0");
	ob->sprites = ob->animator.animation[idle].frames[0];
	ob->draw = draw;
	destroy_sprite(&sprite);
}

void	make_fence(void)
{
	t_object	*a;
	t_object	*b;

	a = (*object(First));
	b = (*object(First));
	while (a)
	{
		if (a->type == '1' && b->type == '1')
		{
			if (a->position.x + 64 == b->position.x && a->position.y == \
			b->position.y)
				new_fence_w(new_vector2(a->position.x + 21, a->position.y + 3), \
				"xpm/wall2.xpm");
			if (a->position.y + 64 == b->position.y && a->position.x == \
			b->position.x)
				new_fence_h(new_vector2(a->position.x + 5, a->position.y + 30), \
				"xpm/fence.xpm");
		}
		b = b->next;
		if (!b)
		{
			a = a->next;
			b = (*object(First));
		}
	}
}
