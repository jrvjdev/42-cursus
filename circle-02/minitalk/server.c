/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:24:11 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/17 16:53:50 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hendle_signal(int sig)
{
	static char	c;
	static int	index;

	c |= (31 - sig) << index;
	if (index == 7)
	{
		if (!c)
			write(1, "1 NULL\n", 7);
		write(1, &c, 1);
		index = 0;
		c = 0;
	}
	else
		index++;
}

int	main(int ac, char **av)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, hendle_signal);
	signal(SIGUSR2, hendle_signal);
	while (1)
		pause();
	return (0);
}
