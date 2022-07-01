/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:15:41 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:15:44 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef int	t_call(const char *format, va_list *ap);

int			ft_printf(const char *format, ...);
int			ft_call_p(const char *format, va_list *ap);
int			ft_call_u(const char *format, va_list *ap);
int			ft_call_upx(const char *format, va_list *ap);
int			ft_call_int(const char *format, va_list *ap);
int			ft_call_lowx(const char *format, va_list *ap);
int			ft_call_char(const char *format, va_list *ap);
int			ft_call_string(const char *format, va_list *ap);
int			ft_call_percentage(const char *format, va_list *ap);

#endif
