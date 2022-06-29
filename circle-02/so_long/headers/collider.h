/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:40:10 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 01:58:35 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLIDER_H
# define COLLIDER_H

# include <stdlib.h>

# include "type.h"
# include "vector2.h"
# include "mlx.h"
# include "object.h"

void		check_collision(t_object *cursor, t_vector2 *translate, \
				t_vector2 v);
int			col_x(t_object *a, t_object *b, int x);
int			col_y(t_object *a, t_object *b, int x);
t_collider	*new_collider(int x, int y, int w, int h);

#endif
