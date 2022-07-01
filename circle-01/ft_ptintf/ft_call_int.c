/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:14:28 by joaoribeiro       #+#    #+#             */
/*   Updated: 2021/12/18 01:14:30 by joaoribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_number_to_str(int nb, char ptr[12], int *index, char *base)
{
	if (nb < -9 || nb > 9)
		ft_number_to_str(nb / 10, ptr, index, base);
	ptr[(*index)++] = base[(((nb > 0) - (nb < 0)) * nb) % 10];
}

int	ft_call_int(const char *format, va_list *ap)
{
	int		i;
	int		nb;
	char	ptr[12];

	nb = va_arg(*ap, int);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	i = nb < 0;
	ptr[0] = '-';
	ft_number_to_str(nb, ptr, &i, "0123456789");
	write(1, ptr, i);
	format++;
	return (i);
}
