/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_lowx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:14:35 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:14:39 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_number_to_str(unsigned int nb, char ptr[12], int *i, char *base)
{
	if (nb > 15)
		ft_number_to_str(nb / 16, ptr, i, base);
	ptr[(*i)++] = base[nb % 16];
}

int	ft_call_lowx(const char *format, va_list *ap)
{
	int					i;
	unsigned int		nb;
	char				ptr[12];

	i = 0;
	nb = va_arg(*ap, int);
	ft_number_to_str(nb, ptr, &i, "0123456789abcdef");
	write(1, ptr, i);
	format++;
	return (i);
}
