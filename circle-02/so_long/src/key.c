/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:09:07 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:09:08 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/key.h"

t_key	*key(void)
{
	static t_key	key;

	return (&key);
}
