/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:55:22 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:10:35 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"

t_bool	error(char *str, void (*f)(int), int param)
{
	write(1, "Error\n", 6);
	write(1, str, str_len(str));
	if (f)
		f(param);
	return (true);
}
