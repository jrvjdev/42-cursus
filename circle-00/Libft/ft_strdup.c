/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:47 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/30 09:35:31 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
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
