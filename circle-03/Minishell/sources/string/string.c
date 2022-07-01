/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:10:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 10:42:29 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

t_string	string(void)
{
	static t_string	_string = {
		length,
		equals,
		contains,
		index_of,
		beginning_equals,
		split_char,
		split_string,
		dup
	};

	return (_string);
}
