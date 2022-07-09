#include "../../includes/minishell.h"

void	sig_int(int sig)
{
	if (sig == SIGINT)
	{
		printf("(newline)\n");
		// rl_replace_line("", 0);
		// rl_on_new_line();
		// rl_redisplay();
	}
}
void	sig_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("(quit)\n");
	}
}
void	init_termios(void)
{
	struct sigaction	sa_ctrc;
	struct sigaction	sa_ctrd;
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag &= (~ECHOCTL);
	tcsetattr(0, TCSANOW, &term);

	sa_ctrc.sa_handler = &sig_int;
	sa_ctrd.sa_handler = &sig_quit;
	sa_ctrc.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_ctrc, NULL);
	sigaction(SIGQUIT, &sa_ctrd, NULL);
}

/* handle

◦ ctrl-C displays a new prompt on a new line. 
◦ ctrl-D exits the shell.
◦ ctrl-\ does nothing.
*/
