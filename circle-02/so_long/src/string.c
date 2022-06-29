/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:19:26 by joaoribeiro       #+#    #+#             */
/*   Updated: 2022/03/14 01:46:32 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/string.h"

int	str_len(char *str)
{
	if (*str && *str != '\n')
		return (1 + str_len(str + 1));
	else
		return (0);
}

void	str_char(char *str)
{
	if (*str)
	{
		if (*str == 'P')
			map()->player++;
		if (*str == 'C')
			map()->collectible++;
		if (*str == 'E')
			map()->exit++;
		str_char(str + 1);
	}
}

int	str_to_int(int number, char **arr)
{
	number += **arr - 48;
	if ((*arr)++ && **arr >= 48 && **arr <= 57)
		return (str_to_int(number * 10, arr));
	else
		return (number + (!(*arr)++));
}
