/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:51:41 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:16:28 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "../headers/so_long.h"
# include "type.h"

int			size_sprite(char *str);
t_sprite	new_sprite(char *filename);
void		destroy_sprite(t_sprite *sprite);

#endif
