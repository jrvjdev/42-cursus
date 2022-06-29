/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:22:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 01:59:01 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "mlx.h"
# include "hook.h"
# include "color.h"
# include "sprite.h"
# include "window.h"
# include "program.h"
# include "object.h"
# include "animation.h"
# include "player.h"
# include "enemy.h"
# include "pole.h"
# include "background.h"
# include "map.h"
# include "init_all.h"

int	create_trgb(int t, int r, int g, int b);

#endif
