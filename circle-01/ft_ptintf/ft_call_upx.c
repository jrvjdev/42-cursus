/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_upx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:15:18 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:15:22 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_number_to_str(unsigned int nb, char ptr[12], int *i, char *base)
{
	if (nb > 15)
		ft_number_to_str(nb / 16, ptr, i, base);
	ptr[(*i)++] = base[nb % 16];
}

int	ft_call_upx(const char *format, va_list *ap)
{
	int					i;
	unsigned int		nb;
	char				ptr[12];

	i = 0;
	nb = va_arg(*ap, int);
	ft_number_to_str(nb, ptr, &i, "0123456789ABCDEF");
	write(1, ptr, i);
	format++;
	return (i);
}
