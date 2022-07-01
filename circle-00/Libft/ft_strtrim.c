/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:20:45 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:20:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

static int	search_index(int index, char const *s1, char const *set)
{
	while (is_set(s1[index], set) == 1)
		index++;
	return (index);
}

static int	search_length(int length, char const *s1, char const *set)
{
	while (is_set(s1[length], set) == 1)
		length--;
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		length;
	int		temp;
	int		count;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	index = 0;
	count = 0;
	length = ft_strlen(s1) - 1;
	index = search_index(index, s1, set);
	length = search_length(length, s1, set);
	while (index + count <= length)
		count++;
	ptr = malloc((count + 1) * sizeof(char));
	if (!ptr)
		return (0);
	temp = -1;
	while (temp++ < count - 1)
		ptr[temp] = s1[index + temp];
	ptr[temp] = '\0';
	return (ptr);
}
