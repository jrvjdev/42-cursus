/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:04 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:19:06 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstptr;
	char	*srcptr;

	dstptr = (char *)(dst);
	srcptr = (char *)(src);
	if (dstptr && srcptr)
	{
		while (n--)
			*dstptr++ = *srcptr++;
	}
	return (dst);
}
