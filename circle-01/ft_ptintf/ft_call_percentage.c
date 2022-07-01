/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_percentage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:14:57 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:14:59 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_call_percentage(const char *format, va_list *ap)
{
	if (*format == '%' && (ap || !ap))
		write(1, format++, 1);
	return (1);
}
