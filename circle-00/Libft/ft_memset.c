/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:14 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:42:40 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param pointer pointer to the block of memory to fill.
 * @param set value to be set. The value is passed as an int, but 
 * the function fills the block of memory using the unsigned char 
 * conversion of this value.
 * @param length number of bytes to be set to the value.
 * @return pointer to the memory area pointer.
 */
void	*ft_memset(void *pointer, int set, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
		*((unsigned char *)pointer + index++) = (unsigned char)set;
	return (pointer);
}
