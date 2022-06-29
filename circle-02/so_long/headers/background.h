/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:48:45 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 20:48:48 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H

# include <stdlib.h>

# include "mlx.h"
# include "type.h"
# include "animation.h"
# include "window.h"

void	new_background(t_vector2 size, char *file_name);

#endif
