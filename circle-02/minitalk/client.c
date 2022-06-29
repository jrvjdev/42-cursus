/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:02:19 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/17 17:04:13 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	*get_pid(void)
{
	static pid_t	pid;

	return (&pid);
}

void	send_signal(char *str)
{
	int		index;

	index = 0;
	while (*str)
	{
		if (kill((*get_pid()), 31 - ((*str >> index++) & 1)))
			exit(write(2, "Error: kill\n", 12));
		if (index > 7)
		{
			index = 0;
			str++;
		}
		usleep(20);
	}
}

int	main(int ac, char **av)
{
	(*get_pid()) = atoi(*(++av));
	while (*(++av))
		send_signal(*av);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	usleep(20);
	kill((*get_pid()), SIGUSR2);
	return (0);
}
