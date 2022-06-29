/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:41:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/04 23:29:32 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sprite.h"

int	size_sprite(char *str)
{
	if (!str || !*str)
		return (1);
	else
		return ((*str == ',') + size_sprite(str + 1));
}

t_sprite	new_sprite(char *filename)
{
	t_sprite	sprite;

	sprite.img_ptr = mlx_xpm_file_to_image(program()->mlx_ptr, filename,
			&sprite.size.x, &sprite.size.y);
	if (!sprite.img_ptr)
		destroy_all_object();
	sprite.pixels = mlx_get_data_addr(sprite.img_ptr, &sprite.bits_per_pixel,
			&sprite.size_line, &sprite.endian);
	return (sprite);
}

void	destroy_sprite(t_sprite *sprite)
{
	if (sprite->img_ptr)
		mlx_destroy_image(program()->mlx_ptr, sprite->img_ptr);
	sprite->img_ptr = NULL;
}
