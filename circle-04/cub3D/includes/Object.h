/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:53:31 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/03 20:14:19 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "Vector3.h"

typedef struct s_object	t_object;

struct s_object
{
	t_vector3	*position;
	t_object	*up;
	t_object	*up_right;
	t_object	*right;
	t_object	*down_right;
	t_object	*down;
	t_object	*down_left;
	t_object	*left;
	t_object	*up_left;
};

#endif // OBJECT_H
