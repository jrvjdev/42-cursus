/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:17:30 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:42:55 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param pointer  pointer to the block of memory to fill.
 * @param length number of bytes to be set to the value.
 */
void	ft_bzero(void *pointer, size_t length)
{
	ft_memset(pointer, 0, length);
}
