/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:40:57 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 20:52:52 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "program.h"
# include "animation.h"
# include "collider.h"
# include "transform.h"
# include "type.h"
# include "key.h"

void	new_player(t_vector2 position, char *file_name);

#endif
