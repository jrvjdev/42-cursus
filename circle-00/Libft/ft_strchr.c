/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:43 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:19:44 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	if (str[index] == (char)c)
		return ((char *)str);
	while (str[index++] != '\0')
		if (str[index] == (char)c)
			return ((char *)str + index);
	return (NULL);
}
