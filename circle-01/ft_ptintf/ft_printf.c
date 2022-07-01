/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:15:30 by joaoribeiro       #+#    #+#             */
/*   Updated: 2022/06/29 17:08:45 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_call(t_call *call_list[121])
{
	call_list['i'] = &ft_call_int;
	call_list['d'] = &ft_call_int;
	call_list['c'] = &ft_call_char;
	call_list['u'] = &ft_call_u;
	call_list['p'] = &ft_call_p;
	call_list['s'] = &ft_call_string;
	call_list['X'] = &ft_call_upx;
	call_list['x'] = &ft_call_lowx;
	call_list['%'] = &ft_call_percentage;
}

int	ft_call(const char *format, va_list *ap)
{
	static int				i;
	static t_call			*call_list[121];

	if (!i)
		ft_init_call(call_list);
	if (call_list[(unsigned char)*format])
		return (call_list[(unsigned char)*format](format, ap));
	return (0);
}

static int	ft_make_block(const char *format, va_list *ap)
{
	int			index;

	index = 0;
	if (!*format)
		return (0);
	while (format[index] && format[index] != '%')
			index++;
	if (index)
		write(1, format, index);
	format = (format + index);
	if (*format && *format == '%')
		index += ft_call(++format, ap);
	if (!*format)
		return (index);
	return (index + ft_make_block(++format, ap));
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, format);
	i = ft_make_block(format, &ap);
	va_end(ap);
	return (i);
}
