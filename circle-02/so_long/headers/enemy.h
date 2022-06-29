/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 02:22:27 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 01:59:45 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "program.h"
# include "animation.h"
# include "rando_int.h"
# include "type.h"

void	new_enemy(t_vector2 position, char *file_name);

#endif
