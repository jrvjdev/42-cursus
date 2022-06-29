/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rando_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:02:21 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:08:44 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rando_int.h"

// int	rando(int digit, int mseed)
// {
// 	int	i;
// 	int	out;
// 	int	seed;
// 	int	random;

// 	seed = mseed * (long) &(((char *)(&i))[0]);
// 	random = 0;
// 	i = 0;
// 	while (i < 32)
// 	{
// 		out = seed & 1;
// 		seed = (seed >> 1) | (((seed & 1) ^ (seed & 2)) << 31);
// 		random = random | (out << (31 - i));
// 		i++;
// 	}
// 	return (random % digit);
// }

// int	rand_int(int min, int max, int mseed)
// {
// 	unsigned long	i;
// 	int				r;
// 	int				result_table[100];

// 	i = -1;
// 	r = min;
// 	while (++i < (sizeof(result_table) / sizeof(int)))
// 	{
// 		if (r > max)
// 			r = min;
// 		result_table[i] = r++;
// 	}
// 	return (result_table[rando(100, mseed)]);
// }

int	mix(void)
{
	static int	ran = 3251;

	ran = ((ran * (long) &(((char *)(&ran))[0])) / 100) % 10000;
	return (ran);
}

int	rando(int min, int max)
{
	return (mix() % (max + 1 - min) + min);
}
