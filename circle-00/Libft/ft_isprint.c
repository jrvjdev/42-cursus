/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:04 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:55:58 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * 
 * @param c character to be tested.
 * @return 1 if c is a printable character, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
