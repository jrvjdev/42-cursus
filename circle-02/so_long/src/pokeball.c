/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokeball.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:05:18 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 23:08:03 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pokeball.h"

static void	draw(void)
{
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->sprites, \
		(*object(Last))->position.x, (*object(Last))->position.y);
}

static void	update(void)
{
	static int	i;

	if (i++ > 10)
		return ;
	i = 0;
	set_animation((*object(Last))->animator.state);
}

void	new_pokebola(t_vector2 position, char *file_name)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	ob = new_object(position);
	ob->type = 'C';
	ob->collider = new_collider(5, 5, 27, 33);
	sprite = new_sprite(file_name);
	vector2 = new_vector2(12, 4);
	ob->animator.size = 1;
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, \
	"0,1,2,3,4,5,6,7,8,9,10,11");
	ob->animator.animation[up] = new_animation(10, sprite, vector2, \
	"12,13,14,15,16,17,18,19,20,21,22,23");
	ob->animator.animation[down] = new_animation(10, sprite, vector2, \
	"24,25,26,27,28,29,30,31,32,33,34,35");
	ob->animator.animation[left] = new_animation(10, sprite, vector2, \
	"36,37,38,39,40,41,42,43,44,45,46,47");
	ob->animator.state = rando(0, 3);
	ob->animator.animation[ob->animator.state].index = rando(0, 11);
	ob->sprites = ob->animator.animation[ob->animator.state].frames[0];
	destroy_sprite(&sprite);
	ob->update = update;
	ob->draw = draw;
}
