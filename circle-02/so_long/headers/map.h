/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 04:53:25 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 22:06:09 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>

# include "type.h"
# include "string.h"
# include "get_next_line.h"
# include "window.h"
# include "line.h"
# include "error.h"
# include "menu.h"

t_map	*map(void);
void	init_map(void);
void	load_map(char *map_name);

#endif
