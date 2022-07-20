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

t_hashmap *_env_create(char *string)
{
	t_hashmap	*new_node;
	char		**split;

	new_node = _memory().malloc(sizeof(t_env));
	split = _string().split_char(string, '=');
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->key = split[0];
	new_node->value = split[1];
	_list().add_node((void **)_env().list(), new_node);
	_memory().free(split);
	return (new_node);
}