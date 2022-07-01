/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:13:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/27 21:39:10 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

static char	**_char(char *string, char separator, char **list, int index)
{
	int		length;
	char	*new_string;

	while (string && *string == separator)
		string++;
	length = 0;
	while (string[length] != separator && string[length])
		length++;
	new_string = new_malloc(sizeof(char) * (length + 1));
	length = 0;
	while (string && *string && *string != separator)
		new_string[length++] = *string++;
	if (string && *string)
		list = _char(string, separator, list, index +1);
	else
		list = new_malloc(sizeof(char *) * (index + 1));
	list[index] = new_string;
	return (list);
}

static char	**_string(char *string, char *separator, char **list, int index)
{
	int		_index;
	char	*new_string;

	while (string && beginning_equals(string, separator) > 0)
		string += length(separator);
	_index = 0;
	while (!beginning_equals(string + _index, separator) && string[_index])
		_index++;
	new_string = new_malloc(sizeof(char) * (_index + 1));
	_index = 0;
	while (string && *string && !beginning_equals(string, separator))
		new_string[_index++] = *string++;
	if (string && *string)
		list = _string(string, separator, list, index +1);
	else
		list = new_malloc(sizeof(char *) * (index + 1));
	list[index] = new_string;
	return (list);
}

char	**split_char(char *string, char separator)
{
	return (_char(string, separator, NULL, 0));
}

char	**split_string(char *string, char *separator)
{
	return (_string(string, separator, NULL, 0));
}
