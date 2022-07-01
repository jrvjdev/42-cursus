/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:17:22 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 17:53:48 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * 
 * @param string representation of an integral number.
 * @return string converted to number
 */
int	ft_atoi(const char *string)
{
	int	number;
	int	signal;

	number = 0;
	while ((*string >= '\t' && *string <= '\r') || *string == ' ')
		string++;
	if (*string == '+' || *string == '-')
		signal = 44 - *string++;
	while (*string >= '0' && *string <= '9')
		number = (*string++ - '0') + (number * 10);
	return (number * signal);
}
