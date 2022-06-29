/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:46:38 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 20:49:28 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "type.h"
# include "program.h"
# include "hook.h"
# include "maloc.h"
# include "window.h"
# include "background.h"

t_object	**object(t_option option);
t_object	*new_object(t_vector2 position);
void		destroy_object(t_object *object);
void		destroy_all_object(void);

#endif
