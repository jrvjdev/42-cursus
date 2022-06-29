/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:26:03 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:14:10 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include <stdlib.h>

# include "../headers/so_long.h"
# include "vector2.h"
# include "string.h"
# include "type.h"
# include "program.h"

void		set_animation(t_animation_state state);
t_animation	new_animation(int speed, t_sprite sprites, t_vector2 \
matrix, char *item);

#endif
