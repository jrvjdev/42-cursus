/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 12:36:39 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

t_char	_char(void)
{
	static t_char	_char = {
		_to_lower,
		_to_upper,
		_is_alpha,
		_is_lowercase,
		_is_uppercase,
		_is_whitespace
	};

	return (_char);
}
