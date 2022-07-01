/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:14:48 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:14:52 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_number_to_str(unsigned long nb, char ptr[12], int *i, char *base)
{
	if (nb > 15)
		ft_number_to_str(nb / 16, ptr, i, base);
	ptr[(*i)++] = base[nb % 16];
}

int	ft_call_p(const char *format, va_list *ap)
{
	int					i;
	unsigned long		nb;
	char				ptr[16];

	i = 2;
	nb = va_arg(*ap, unsigned long);
	ptr[0] = '0';
	ptr[1] = 'x';
	ft_number_to_str(nb, ptr, &i, "0123456789abcdef");
	write(1, ptr, i);
	format++;
	return (i);
}
