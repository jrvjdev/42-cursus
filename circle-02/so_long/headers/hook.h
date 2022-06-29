/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:22:22 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 20:49:36 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include <stdlib.h>

# include "so_long.h"
# include "type.h"
# include "rando_int.h"
# include "window.h"
# include "background.h"
# include "key.h"

int	key_up(int key);
int	key_down(int key);
int	loop_hook(void);

#endif
