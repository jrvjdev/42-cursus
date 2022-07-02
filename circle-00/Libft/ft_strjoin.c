/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:56 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/02 09:55:09 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		length_s1;
	int		length_s2;

	if (!s1 || !s2)
		return (NULL);
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s1);
	string = malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_memcpy(string, s1, length_s1);
	ft_memcpy(string + length_s1, s2, length_s2);
	return (string);
}
