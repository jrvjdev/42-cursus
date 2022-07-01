/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:14:21 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:14:23 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_call_char(const char *format, va_list *ap)
{
	int	c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	format++;
	return (1);
}
