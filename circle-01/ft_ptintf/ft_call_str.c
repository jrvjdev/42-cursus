/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:15:03 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:15:06 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_call_string(const char *format, va_list *ap)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = va_arg(*ap, char *);
	if (!ptr)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (ptr[i])
		i++;
	write(1, ptr, i);
	format++;
	return (i);
}
