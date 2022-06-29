/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:04:32 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:16:06 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <unistd.h>

# include "type.h"
# include "map.h"
# include "window.h"
# include "player.h"
# include "exit.h"
# include "pokeball.h"
# include "pole.h"
# include "fence.h"
# include "rando_int.h"

t_line	**line(int ops);
t_line	*new_line(char *str);
void	free_line(void);
int		check_line(char *str, int ops);
void	read_line(t_vector2 v);
t_line	*add_line(t_line **first, t_line **last, t_line *new_line);

#endif
