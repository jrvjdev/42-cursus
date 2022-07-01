/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:10 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:19:11 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)(dst);
	s = (char *)(src);
	if (d && s)
	{
		if ((s < d) && (d < (s + len)))
		{
			s += len;
			d += len;
			while (len--)
				*--d = *--s;
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
