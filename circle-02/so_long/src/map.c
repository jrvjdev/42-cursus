/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:09:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 01:31:57 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/map.h"

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

void	init_map(void)
{
	map()->top = 1;
	map()->mid = 1;
	map()->down = 1;
	map()->line = -1;
	map()->column = 0;
	map()->player = 0;
	map()->collectible = 0;
	map()->exit = 0;
	map()->time = 60;
	map()->steps = 0;
}

t_line	**line(int ops)
{
	static t_line	*first;
	static t_line	*last;

	if (ops)
		return (&last);
	else
		return (&first);
}

void	check_map(int fd)
{
	while (add_line(line(First), line(Last), new_line(get_next_line(fd))))
	{
		if (map()->line < 0)
		{
			map()->line = str_len((*line(Last))->str);
			(map())->top = check_line((*line(Last))->str, 0);
		}
		else
		{
			map()->line *= (map()->line == str_len((*line(Last))->str));
			(map())->mid *= check_line((*line(Last))->str, 1);
		}
		(map())->down = check_line((*line(Last))->str, 0);
		str_char((*line(Last))->str);
		map()->column++;
	}
	if (!map()->player || !map()->collectible || !map()->exit || !map()->line \
	|| !map()->top || !map()->mid || !map()->down)
		return ;
	(window())->size.x = map()->line * 64;
	if (map()->line < 23)
		(window())->size.x = 23 * 64;
	new_background(new_vector2(0, 0), "xpm/ground.xpm");
	new_menu(new_vector2(50, 50));
	make_fence();
}

void	load_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error("Invalid map.ber file path", exit, 1);
	check_map(fd);
	close(fd);
	free_line();
	!map()->line && error("invalid map format", exit, 1);
	!map()->top && error("invalid map format", exit, 1);
	!map()->mid && error("invalid map format", exit, 1);
	!map()->down && error("invalid map format", exit, 1);
	!map()->player && error("The map must contain at least 1 \
	starting position", exit, 1);
	!map()->collectible && error("The map must contain at least 1 \
	collectible", exit, 1);
	!map()->exit && error("The map must contain at least 1 \
	exit", exit, 1);
}
