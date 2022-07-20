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

// #include "minitalk.h"

// void	hendle_signal(int sig)
// {
// 	static char	c;
// 	static int	index;

// 	c |= (31 - sig) << index;
// 	if (index == 7)
// 	{
// 		if (!c)
// 			write(1, "1 NULL\n", 7);
// 		write(1, &c, 1);
// 		index = 0;
// 		c = 0;
// 	}
// 	else
// 		index++;
// }

// int	main(int ac, char **av)
// {
// 	printf("%d\n", getpid());
// 	signal(SIGMINE, hendle_signal);
// 	signal(SIGUSR2, hendle_signal);
// 	while (1)
// 		pause();
// 	return (0);
// }

#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <signal.h>

void sig_hnd(int sig)
{
	(void)sig;
	printf("(VINTR)");
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	struct termios old_termios, new_termios;
	tcgetattr(0, &old_termios);

	signal(SIGINT, sig_hnd);

	new_termios = old_termios;
	new_termios.c_cc[VEOF] = 3;	 // ^C
	new_termios.c_cc[VINTR] = 4; // ^D
	tcsetattr(0, TCSANOW, &new_termios);

	char line[256];
	int len;
	do
	{
		len = read(0, line, 256);
		line[len] = '\0';
		if (len < 0)
			printf("(len: %i)", len);
		if (len == 0)
			printf("(VEOF)");
		if (len > 0)
		{
			if (line[len - 1] == 10)
				printf("(line:'%.*s')\n", len - 1, line);
			if (line[len - 1] != 10)
				printf("(partial line:'%s')", line);
		}
	} while (line[0] != 'q');

	tcsetattr(0, TCSANOW, &old_termios);
}

// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

// int main(void)
// {
// 	char *buf = malloc(sizeof(char) * 500);
// 	size_t size = 500;
// 	while (1)
// 	{

// 		int nb = getline(&buf, &size, stdin);
// 		if (nb == -1)
// 			printf("CTRL + D captured\n");
// 		if (nb == 0)
// 			printf("CTRL + C captured\n");
// 		free(buf);
// 		pause();
// 	}
// 	return (0);
// }