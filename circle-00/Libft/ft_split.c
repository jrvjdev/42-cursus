/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:38 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/30 09:37:57 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**_char(char *string, char separator, char **list, int index)
{
	int		length;
	char	*new_string;

	while (string && *string == separator)
		string++;
	length = 0;
	while (string[length] != separator && string[length])
		length++;
	new_string = malloc(sizeof(char) * (length + 1));
	length = 0;
	while (string && *string && *string != separator)
		new_string[length++] = *string++;
	if (string && *string)
		list = _char(string, separator, list, index +1);
	else
		list = malloc(sizeof(char *) * (index + 1));
	list[index] = new_string;
	return (list);
}

char	**ft_split(char *string, char separator)
{
	return (_char(string, separator, NULL, 0));
}
