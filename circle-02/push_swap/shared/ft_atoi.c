/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:44:30 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 20:30:40 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_white_space(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

long	ft_atoi(const char *str)
{
	long	result;
	long	signal;

	result = 0;
	signal = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
		signal = 44 - *str++;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * signal);
}

int	ft_split_atoi(t_list **stack, char **str)
{
	long	result;
	long	signal;

	result = 0;
	signal = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	if (**str == '+' || **str == '-')
		signal = 44 - *(*str)++;
	if (**str >= '0' && **str <= '9')
	{
		while (**str >= '0' && **str <= '9')
			result = (result * 10) + (*(*str)++ - '0');
		lst_add_back(stack, lst_new(result * signal));
	}
	else
		return (-2);
	if (!**str)
		return (-1);
	if (**str == ' ')
		return (0);
	return (1);
}
