/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:03:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:16:49 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stdlib.h>

# include "type.h"
# include "program.h"
# include "../headers/so_long.h"

t_window	*window(void);
void		new_window(t_vector2 size, char *title);

#endif
