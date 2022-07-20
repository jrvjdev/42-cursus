/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:57:32 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/02 11:02:48 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"
#include <stdio.h>

t_hashmap	*_env_get_node(t_hashmap **list, char *key)
{
	if (list && *list)
	{
		if (_string().equals((*list)->key, key))
			return (*list);
		return (_env_get_node(&(*list)->next,key));
	}
	return (NULL);
}

t_hashmap *_env_get(char *key)
{
	return (_env_get_node(_env().list(), key));
}
