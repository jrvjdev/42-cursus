/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:26:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 09:48:21 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

// return the length of the string
size_t	length(char *string)
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

int	is_whitespace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

char	*dup(const char *string)
{
	char	*new_string;
	int		len;

	len = strlen(string);
	new_string = ft_calloc((len + 1), sizeof(char));
	if (!new_string)
		return (NULL);
	while (*string)
		*new_string++ = *string++;
	new_string -= len;
	return (new_string);
}

void	*calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, '\0', count * size);
	return (temp);
}

char	*dup_at(const char *string, size_t size)
{
	size_t	index;
	char	*new_string;

	if (size > length((char *)string))
		size = length((char *)string);
	new_string = calloc((size + 1), sizeof(char));
	if (!new_string)
		return (NULL);
	index = size;
	while (index--)
		*new_string++ = *string++;
	new_string -= size;
	return (new_string);
}

char *trim(char *str)
{
	size_t	_length;

	_length = length(str);
	while (isspace(str[_length - 1]))
		--_length;
	while (*str && isspace(*str))
	{
		++str;
		--_length;
	}

	return (dup(str, _length));
}
