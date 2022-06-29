/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:01:32 by joaoribeiro       #+#    #+#             */
/*   Updated: 2022/03/14 18:35:57 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/animation.h"

t_mlx_img_list	*new_frame(t_sprite sprites, t_vector2 matrix,
	t_vector2 position)
{
	t_vector2		i;
	t_vector2		j;
	t_sprite		sprite;

	sprite.img_ptr = mlx_new_image((program())->mlx_ptr, (sprites.size.x \
	/ matrix.x), (sprites.size.y / matrix.y));
	if (!sprite.img_ptr)
		return (NULL);
	sprite.pixels = mlx_get_data_addr(sprite.img_ptr, &sprite.bits_per_pixel, \
	&sprite.size_line, &sprite.endian);
	i.y = ((sprites.size.y / matrix.y) * position.y) - 1;
	j.y = 0;
	while (++i.y < ((sprites.size.y / matrix.y) * (position.y + 1)))
	{
		i.x = ((sprites.size.x / matrix.x) * position.x) - 1;
		j.x = 0;
		while (++i.x < ((sprites.size.x / matrix.x) * (position.x + 1)))
		{
			set_pixel((&sprite.pixels[j.x * 4 + sprite.size_line * j.y]),
				(&sprites.pixels[i.x * 4 + sprites.size_line * i.y]));
			j.x++;
		}
		j.y++;
	}
	return (sprite.img_ptr);
}

t_animation	new_animation(int speed, t_sprite sprites, t_vector2 matrix, \
char *item)
{
	t_animation				animation;
	t_vector2				position;
	t_index					index;
	int						size;

	index.y = size_sprite(item);
	animation.index = 0;
	animation.time = 0;
	animation.speed = speed;
	animation.loop = true;
	index.x = -1;
	while (++index.x < index.y)
	{
		size = str_to_int(0, &item);
		position.y = size / matrix.x;
		position.x = size - (position.y * matrix.x);
		animation.frames[index.x] = new_frame(sprites, matrix, position);
		animation.size = index.x + 1;
		if (!animation.frames[index.x])
			return (animation);
	}
	return (animation);
}

void	set_animation(t_animation_state state)
{
	(*object(Last))->animator.animation->time += \
	(*object(Last))->animator.animation->speed;
	if ((*object(Last))->animator.state == state)
	{
		if ((*object(Last))->animator.animation->time > 100)
		{
			(*object(Last))->animator.animation[state].index++;
			(*object(Last))->animator.animation->time = 0;
		}
	}
	else
		(*object(Last))->animator.animation->time = 0;
	if ((*object(Last))->animator.animation[state].index >= \
	(*object(Last))->animator.animation[state].size)
	{
		if ((*object(Last))->animator.animation[state].loop)
			(*object(Last))->animator.animation[state].index = 0;
		else
			(*object(Last))->animator.animation[state].index--;
	}
	(*object(Last))->sprites = (*object(Last))->animator.\
		animation[state].frames[(*object(Last))->animator.animation[state].\
		index];
	(*object(Last))->animator.state = state;
}
