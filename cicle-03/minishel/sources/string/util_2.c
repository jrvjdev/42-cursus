/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:26:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/28 22:24:04 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

// return the length of the string
int	length(char *string)
{
	if (string && *string)
		return (1 + length(++string));
	return (0);
}

t_hashmap	*new_hashmap(char *string)
{
	t_hashmap	*new_hashmap;
	char		**split;

	new_hashmap = new_malloc(sizeof(t_hashmap));
	split = split_char(string, '=');
	new_hashmap->key = split[0];
	new_hashmap->value = split[1];
	return (new_hashmap);
}
