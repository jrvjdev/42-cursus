/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:57:42 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/28 22:57:56 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "string.h"

typedef struct s_env t_env;

struct s_env
{
	t_hashmap *(*create)(char *hashmap);
	t_hashmap *(*get)(char *key);
	t_hashmap **(*list)(void);
};

t_env		_env(void);

t_hashmap	**_env_list(void);
t_hashmap	*_env_get(char *key);
t_hashmap 	*_env_create(char *hashmap);

#endif
